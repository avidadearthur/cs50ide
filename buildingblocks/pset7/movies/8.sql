-- write a SQL query to list the names of all people who starred in Toy Story.
-- Your query should output a table with a single column for the name of each person.
-- You may assume that there is only one movie in the database with the title Toy Story.
SELECT people.name FROM people INNER JOIN stars ON people.id = stars.person_id WHERE stars.movie_id IN (SELECT id FROM movies WHERE title = 'Toy Story');