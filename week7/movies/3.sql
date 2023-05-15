-- movies released between 2018 and now, in alphabetical order
SELECT title
FROM movies
WHERE year >= 2018
ORDER BY(title);