#ifndef MOCK_UNITTEST_UTILS_HPP_
#define MOCK_UNITTEST_UTILS_HPP_

#include "errors.hpp"
#include <boost/function.hpp>

#include "containers/scoped.hpp"

namespace mock {

class temp_file_t {
public:
    explicit temp_file_t(const char *tmpl);
    const char *name() { return filename.data(); }
    ~temp_file_t();

private:
    scoped_array_t<char> filename;

    DISABLE_COPYING(temp_file_t);
};

void let_stuff_happen();

int randport();

void run_in_thread_pool(const boost::function<void()>& fun, int num_workers = 1);

}  // namespace mock

#endif /* MOCK_UNITTEST_UTILS_HPP_ */
