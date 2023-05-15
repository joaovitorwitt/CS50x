-- movies released in 2010 and their ratings, descending order by rating, if same rating, order alphabetically
SELECT title, rating
FROM movies
JOIN ratings on movies.id = ratings.movie_id
    WHERE year = 2010
    ORDER BY rating DESC, title;