-- return average energy of songs by Drake
SELECT AVG(energy)
FROM SONGS
JOIN artists
    ON songs.artist_id = artists.id
WHERE artists.name LIKE "%drake%";