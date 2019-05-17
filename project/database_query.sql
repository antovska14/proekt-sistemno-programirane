DROP DATABASE IF EXISTS routes_database;
CREATE DATABASE routes_database;
USE routes_database;

CREATE TABLE IF NOT EXISTS ROUTES(
	id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    startDestination VARCHAR(60) NOT NULL,
    endDestination VARCHAR(60) NOT NULL,
    distance DECIMAL NOT NULL,
    duration DECIMAL NOT NULL
);

DELIMITER | 
CREATE PROCEDURE ADD_ROUTE(paramStart VARCHAR(100), paramEnd VARCHAR(100),
 paramDistance DECIMAL, paramDuration DECIMAL)
BEGIN
DECLARE currentId INT;
DECLARE currentDuration INT;

SET currentId = (SELECT id FROM ROUTES WHERE startDestination = paramStart AND endDestination = paramEnd);
SET currentDuration = (SELECT duration FROM ROUTES WHERE id = currentId AND duration > paramDuration);

IF( currentId IS NOT NULL ) THEN
	IF( currentDuration IS NOT NULL ) THEN
		UPDATE ROUTES
		SET duration = paramDuration
		WHERE id = currentId;
    END IF;
ELSE 
	INSERT INTO ROUTES(startDestination, endDestination, distance, duration) 
    VALUES(paramStart,paramEnd,paramDistance,paramDuration);
END IF;

END
|
DELIMITER ;

SELECT * FROM ROUTES;