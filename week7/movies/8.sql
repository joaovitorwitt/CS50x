-- all of the people that starred in ToyStory
SELECT name
FROM people
JOIN stars on people.id = stars.person_id
JOIN movies on stars.movie_id = movies.id
    WHERE title = "Toy Story";