#' Get all the ratings from one song's filename
#' @inheritParams default_params_doc
#' @examples
#' get_song_ratings(
#'   song_filename = get_song_path("10000Luchtballonnen.md")
#' )
#' @seealso use \link{get_song_rating} to get the ratings
#'   specifically for a reviewer and formation
#' @export
get_song_ratings <- function(
  song_filename
) {
  testthat::expect_true(file.exists(song_filename))

  df <- tibble::as_tibble(
    expand.grid(
      formation = c("KKK", "JKK", "HKM"),
      reviewer = c("Richel", "Mark")
    )
  )
  df$rating <- NA
  for (row_index in seq_len(nrow(df))) {
    df$rating[row_index] <- k3reviews::get_song_rating(
      song_filename = song_filename,
      reviewer_name = df$reviewer[row_index],
      formation = df$formation[row_index]
    )
  }
  df
}
