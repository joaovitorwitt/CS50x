-- 1st query
UPDATE shows SET title = "How I Met Your Mother" WHERE title = "How i met your mother";

-- compare all the titles with the distinct titles
SELECT COUNT(title), COUNT(DISTINCT(title)) FROM shows;

-- 2nd query
UPDATE shows SET title = "Adventure Time" WHERE title LIKE "adventur%";

-- 3rd query
UPDATE shows SET title = "Arrow" WHERE title LIKE "%arrow%";

-- 4th query
UPDATE shows SET title = "Avatar: The Last Airbender" WHERE title LIKE "avatar%";

-- 5th query
UPDATE shows SET title = "Sherlock" WHERE title LIKE "sherlock%";

-- 6th query
UPDATE shows SET title = "Brooklyn Nine-Nine" WHERE title LIKE "brooklyn%" OR title LIKE "%B99%";

-- 7th query
UPDATE shows SET title = "Community" WHERE title LIKE "%community%";

-- 8th query
UPDATE shows SET title = "Family Guy" WHERE title LIKE "%family guy%";

-- 9th query
UPDATE shows SET title = "Friends" WHERE title LIKE "%friends%";

-- 10th query
UPDATE shows SET title = "Game of Thrones" WHERE title LIKE "%got%" or title LIKE "%game of thrones%";

-- 11th query
UPDATE shows SET title = "Gilmore Girls" WHERE title LIKE "gilmore%";

-- 12th query
UPDATE shows SET title = "Grey's Anatomy" WHERE title LIKE "grey%";

-- 13th query
UPDATE shows SET title = "It's Always Sunny in Philadelphia" WHERE title LIKE "%delphia";

-- 14th query
UPDATE shows SET title = "Parks and Recreation" WHERE title LIKE "parks%";

-- 15th query
UPDATE shows SET title = "Squid Game" WHERE title LIKE "squid%";

-- 16th query
UPDATE shows SET title = "The Bachelorette" WHERE title LIKE "%bachelorette%";

-- 17th query
UPDATE shows SET title = "The Crown" WHERE title LIKE "%crown%";

-- 18th query
UPDATE shows SET title = "The Office" WHERE title LIKE "%office%";

-- 19th query
UPDATE shows SET title = "The Queen's Gambit" WHERE title LIKE "%gambit%";

-- 20th query
UPDATE shows SET title = "The Untamed" WHERE title like "%untamed%";

-- 21th query
UPDATE shows SET title = "Criminal Minds" WHERE title LIKE "%criminal minds%";

-- 22th query
UPDATE shows SET title = "Billions" WHERE title LIKE "%billions%";