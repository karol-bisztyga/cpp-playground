#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include <random>


int randomNumber(const int from, const int to) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(from, to);

  return dist(mt);
}

std::string randomString(size_t size=20) {
  std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
  std::string result;

  for (size_t i = 0; i < size; ++i) {
    result += str[randomNumber(0, str.size() - 1)];
  }

  return result;
}


using namespace std;

int main() {
  sqlite3 *db;

  if (sqlite3_open("test.db", &db)) {
    throw std::runtime_error("could not open DB");
  }
  if (sqlite3_trace_v2(
      db,
      SQLITE_TRACE_PROFILE,
      [](unsigned, void *, void *preparedStatement, void *) {
        sqlite3_stmt *statement = (sqlite3_stmt *)preparedStatement;
        char *sql = sqlite3_expanded_sql(statement);
        if (sql != nullptr) {
          std::string sqlStr(sql);
          // std::cout << "sql query detected: " << sqlStr << std::endl;
        }
        return 0;
      },
      NULL)) {
        throw std::runtime_error("Failed to set trace callback");
      }

  string createTableQuery = "create table IF NOT EXISTS t(name TEXT, age NUMBER, gender BOOL, hash TEXT);";

  char *err = 0;

  if (sqlite3_exec(db, createTableQuery.c_str(), NULL, 0, &err)) {
    throw std::runtime_error("error executing query [" + createTableQuery + "]: " + std::string(err));
  }

  const size_t AMOUNT = 10000;

  const size_t INSERTS = AMOUNT;
  const size_t SELECTS = AMOUNT;
  const size_t UPDATES = AMOUNT;

  auto totalTimeStart = std::chrono::high_resolution_clock::now();

  // --- INSERTS
  cout << "performing " << INSERTS << " inserts" << std::endl;
  auto insertsStart = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < INSERTS; ++i) {
    string name = randomString(10);
    string age = std::to_string(randomNumber(18,50));
    string gender = std::to_string(randomNumber(0, 1));
    string hash = randomString(50);
    if (i == 0) {
      name = "karol";
    }
    string query = "INSERT INTO t(name, age, gender, hash) values(\""+ name +"\","+ age +","+ gender +",\""+ hash +"\");";
    if (sqlite3_exec(db, query.c_str(), NULL, 0, &err)) {
      throw std::runtime_error("error executing query [" + query + "]: " + std::string(err));
    }
  }
  auto insertsStop = std::chrono::high_resolution_clock::now();
  auto insertsTime = std::chrono::duration_cast<std::chrono::milliseconds>(insertsStop-insertsStart).count();

  // --- SELECTS
  cout << "performing " << SELECTS << " selects" << std::endl;
  auto selectsStart = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < SELECTS; ++i) {
    string query = "SELECT * FROM t;";
    if (sqlite3_exec(db, query.c_str(), NULL, 0, &err)) {
      throw std::runtime_error("error executing query [" + query + "]: " + std::string(err));
    }
  }
  auto selectsStop = std::chrono::high_resolution_clock::now();
  auto selectsTime = std::chrono::duration_cast<std::chrono::milliseconds>(selectsStop-selectsStart).count();

  // --- UPDATES
  cout << "performing " << UPDATES << " updates" << std::endl;
  auto updatesStart = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < UPDATES; ++i) {
    string query = "UPDATE t SET hash = \"" + randomString(50) + "\" where name=\"karol\";";
    if (sqlite3_exec(db, query.c_str(), NULL, 0, &err)) {
      throw std::runtime_error("error executing query [" + query + "]: " + std::string(err));
    }
  }
  auto updatesStop = std::chrono::high_resolution_clock::now();
  auto updatesTime = std::chrono::duration_cast<std::chrono::milliseconds>(updatesStop-updatesStart).count();

  // --- DELETE - not measured
  string query = "DELETE FROM t WHERE 1;";
  if (sqlite3_exec(db, query.c_str(), NULL, 0, &err)) {
    throw std::runtime_error("error executing query [" + query + "]: " + std::string(err));
  }

  auto totalTimeStop = std::chrono::high_resolution_clock::now();
  auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(totalTimeStop-totalTimeStart).count();
  std::cout << "inserts time: " << insertsTime << endl;
  std::cout << "selects time: " << selectsTime << endl;
  std::cout << "updates time: " << updatesTime << endl;
  std::cout << "total time: " << totalTime << endl;

  sqlite3_close(db);

  return 0;
}