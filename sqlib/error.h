#pragma once

#include <stdexcept>
#include <sqlite3.h>

namespace sqlib {

class sql_error : public std::logic_error {
 public:
  sql_error(int errcode)
   : sql_error ("sql_error", errcode)
  {
  }

  sql_error(const std::string & msg, int errcode)
   : std::logic_error(msg + ": " + sqlite3_errstr (errcode))
  {
  }

  sql_error(const std::string & msg)
    : std::logic_error (msg)
  {
  }
};

class prepare_error : public sql_error {
 public:

  prepare_error(const std::string & sql, int errcode)
   : sql_error("prepare failed with \"" + sql + "\"", errcode) {
  }
};

class execute_error : public sql_error {
 public:
  execute_error(int errcode)
   : sql_error("execute_query failed", errcode)
  {
  }
};

class busy_error : public sql_error {
 public:
  busy_error()
   : sql_error("busy") {
  }
};

class misuse_error : public sql_error {
 public:
  misuse_error()
   : sql_error("misuse") {
  }
};

} // sqlib
