-- top 5 chadwick boseman movies
SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people on stars.person_id = people.id
JOIN ratings on movies.id = ratings.movie_id
    WHERE name = "Chadwick Boseman" ORDER BY rating DESC LIMIT 5;