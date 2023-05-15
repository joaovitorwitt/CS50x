-- songs that include other aritsts
SELECT name
FROM songs
WHERE name LIKE "%feat.%";