#include "review.h"
#include "reviews.h"
#include "helper.h"

// Boost.Test does not play well with -Weffc++
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include <boost/test/unit_test.hpp>

using namespace kdr;

BOOST_AUTO_TEST_CASE(test_get_review)
{
  const auto rs = get_reviews();
  BOOST_REQUIRE(!rs.empty());
  const review r = rs.back();
  BOOST_CHECK(!r.get_grades().empty());

}

BOOST_AUTO_TEST_CASE(test_Richels_analysis_is_not_a_review)
{
  const std::string md_filename{
    get_default_folder_name() + std::string("/AnalysisRichel.md")
  };
  BOOST_REQUIRE(is_regular_file(md_filename));
  BOOST_CHECK_THROW(
    review r(md_filename),
    std::invalid_argument
  );

}

#pragma GCC diagnostic pop


