#include "review.h"

#include <cassert>

#include "helper.h"
#include "reviewer.h"

kdr::review::review(const std::string& md_filename)
{
  assert(is_regular_file(md_filename));
  const auto text = file_to_vector(md_filename);
}

std::vector<std::pair<double,kdr::reviewer>> kdr::get_grades(
  const std::string& md_filename
)
{
  const auto text = get_header(md_filename);
  for (const auto line: text)
  {
    //Search for ': ?/10'
  }
}

