-- list the songs that have danceability, energy and valence grater than 0.75
SELECT name FROM songs WHERE danceability > 0.75 and valence > 0.75 and energy > 0.75;