-- list title and release years of all harry potter movies, in chronological order
SELECT title, year
FROM movies
WHERE title LIKE "Harry Potter%"
ORDER BY(year);