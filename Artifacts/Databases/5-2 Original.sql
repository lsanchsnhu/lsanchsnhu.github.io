INSERT INTO hr.person (first_name, last_name, gender, age)
	VALUES ('Jack', 'Smith', 'M', 45);
	
INSERT INTO hr.department (dept_name, building)
	VALUES ('Engineering', 'Building 5');
	
INSERT INTO hr.person_department (person_id, dept_id)
	VALUES ((SELECT person_id FROM hr.person WHERE UPPER(first_name) = 'JACK' AND UPPER(last_name) = 'SMITH'),
			(SELECT dept_id FROM hr.department WHERE UPPER(dept_name) = 'ENGINEERING'));			
			
INSERT INTO hr.person (first_name, last_name, gender, age, favorite_book)
	VALUES ('Luc', 'Sanchez', 'M', 26, 'The Dark Tower');
	
INSERT INTO hr.department (dept_name, building)
	VALUES ('Computer Science', 'Mudd');
	
INSERT INTO hr.person_department (person_id, dept_id)
	VALUES ((SELECT person_id FROM hr.person WHERE UPPER(first_name) = 'LUC' AND UPPER(last_name) = 'SANCHEZ'),
			(SELECT dept_id FROM hr.department WHERE UPPER(dept_name) = 'COMPUTER SCIENCE'));