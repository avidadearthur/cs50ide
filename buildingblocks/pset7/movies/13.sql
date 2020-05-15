-- write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
-- Your query should output a table with a single column for the name of each person.
-- There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
-- Kevin Bacon himself should not be included in the resulting list.
SELECT DISTINCT(people.name) FROM people INNER JOIN stars ON people.id = stars.person_id WHERE stars.movie_id IN (SELECT movies.id FROM movies INNER JOIN stars ON movies.id = stars.movie_id WHERE stars.person_id IN (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958)) AND people.name != "Kevin Bacon";