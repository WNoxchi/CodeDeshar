-- 2017-Oct-17 03:29
-- WNixalo
-- SQL practice from http://www.sqlcourse2.com/

create table employee_wnxborz
    (firstname varchar(15),
     lastname varchar(20),
     title varchar(30),
     age number(3),
     salary number(9,2)
    );

insert into tablename
    (first_column, ..., last_column)
    values (first_value,..., last_value);

insert into employee_wnxborz
    (firstname, lastname, title, age, salary)
    values ('Jonie', 'Weber','Secretary',28,19500.00)

update tablename
    set columnname = newvalue
    [, nextcolumn = newvalue2 ...]
    where columname
         OPERATOR value
        [and|or column
         OPERATOR value];

update phone_book
    set area_code = 623
    where prefix = 979;

update phone_book
    set last_name = 'Smith', prefix=555, suffix=9292
    where last_name = 'Jones';

update employee
    set age = age+1
    where first_name='Mary' and last_name='Williams';


update employee_wnxborz
    set lastname = 'Weber-Williams'
    where lastname = 'Weber' and firstname = 'Jonie';

update employee_wnxborz
    set age = age+1
    where firstname = 'Dirk' and lastname='Smith';

update employee_wnxborz
    set title = 'Administrative Assistant'
    where title = 'Secretary';

update employee_wnxborz
    set salary = salary + 3500
    where salary < 30000;

update employee_wnxborz
    set salary = salary + 4500
    where salary > 33500;

update employee_wnxborz
    set title = 'Programmer II' where title = 'Programmer';

update employee_wnxborz
    set tile = 'Programmer III' where title = 'Programmer II';


delete from tablename
    where columnname
        OPERATOR value
    [and|or column
        OPERATOR value];

    [ ] = optional

delete from emploee;  -- deletes all

delete from employee where lastname = 'May';

delete from employee
    where firstname = 'Mike' or firstname = 'Eric';


------------------------------------------------------------------------
-- 2017-Oct-26 13:44 -- SQLCourse2 -- http://www.sqlcourse2.com/

SELECT customerid, item, price FROM items_ordered WHERE customerid = 10449;

SELECT * FROM items_ordered WHERE item = 'Tent';

SELECT customerid, order_date, item FROM items_ordered WHERE item LIKE 'S%';

SELECT DISTINCT item FROM items_ordered;


SELECT MAX(price) FROM items_ordered;

SELECT AVG(price) FROM items_ordered WHERE order_date LIKE '%-Dec-%';

SELECT COUNT(*) FROM items_ordered;

SELECT MIN(price) FROM items_ordered WHERE item = 'tent';


-- what if you also want to display their lastname in the query below:
SELECT max(salary), dept
FROM employee
GROUP BY dept;

-- what you'll need to do is:
SLEECT lastname, max(salary), dept
FROM employee
GROUP BY dept, lastname;
-- this is called multiple grouping columns

-- example:
SELECT quantity, max(price)
FROM items_ordered
GROUP BY quantity;


SELECT state count(state) FROM customers GROUP BY state;

SELECT item, MAX(price), MIN(price) FROM items_ordered GROUP BY item;

select customerid, count(order_date), SUM(price) from items_ordered group by customerid;
select customerid, count(customerid), SUM(price) from items_ordered group by customerid;


-- example
SELECT dept, AVG(salary)
FROM employee
GROUP BY dept
HAVING AVG(salary) > 20000;


SELECT state, COUNT(state) FROM customers GROUP BY state HAVING count(state) > 1;

SELECT item, MAX(price), MIN(price) FROM items_ordered GROUP BY item HAVING MAX(price) > 190;

SELECT customerid, count(customerid), SUM(price)
FROM items_ordered GROUP BY customerid HAVING COUNT(customerid) > 1;


-- ORDER BY clause
SELECT col1, SUM(col2) FROM "list of tables" ORDER BY "col list" [ASC | DESC];

-- example
SELECT employee_id, dept, name, age, salary FROM employee_info
WHERE dept = 'Sales' ORDER BY salary;
-- order based on multiple columns:
SELECT employee_id, dept, name, age, salary
FROM employee_info WHERE dept = 'Sales'
ORDER BY salary, age, DESC;


SELECT lastname, firstname, city
FROM customers
ORDER BY lastname ASC;

SELECT lastname, firstname, city FROM customers ORDER BY lastname DESC;

SELECT item, price FROM items_ordered WHERE price > 10.00
ORDER BY price ASC;


-- Combining Conditions & Boolean Operators
SELECT employee_id, firstnaem, lastname, title, salary
FROM employee_info
WHERE (salary >= 45000.00) AND (title = 'Programmer'); -- `()` not necessary

SELECT customerid, order_date, item FROM items_ordered
WHERE item <> 'Snow Shoes' AND item <> 'Ear Muffs';

SELECT item, price FROM items_ordered
WHERE item LIKE 'S%' OR item LIKE 'P%' OR item LIKE 'F%';


-- IN & BETWEEN
-- IN used like chained ORs, NOT IN used as negative IN
... WHERE x IN (a, b, c)   <->   WHERE x = a, or x = b, or x = b
-- BETWEEN specifies a valid range [a,b]
... x BETWEEN a AND b   <->   x >= a AND x <= b
-- can also use NOT BETWEEN as negative

SELECT order_date, item, price FROM items_ordered
WHERE price BETWEEN 10.00 AND 80.00;

SELECT firstname, city, state from customers
WHERE state IN ('Arizona', 'Washington', 'Oklahoma', 'Colorado', 'Hawaii');


-- Mathematical Functions: http://www.sqlcourse2.com/math.html

SELECT item, price / quantity FROM items_ordered;


-- Table Joins, a must: http://www.sqlcourse2.com/joins.html

-- Inner Join // Equijoin
SELECT customer_info.firstname, customer_info.lastname, purchases.item
FROM customer_info, purchases
WHERE customer_info.customer_number = purchases.customer_number;

-- ANSI SQL-92 syntax spec for Inner Join:
SELECT customer_info.firstname, customer_info.lastname, purchases.item
FROM customer_info INNER JOIN purchases
ON customer_info.customer_number = purchases.customer_number;

-- Another example:
SELECT employee_info.employeeid, employee_info.lastname, employee_sales.comisssion
FROM employee_info, employee_sales
WHERE employee_info.employeeid = employee_sales.employeeid;


-- 1. write a query using a join to det which items were ordered by each of the
--    customers in the customers table. Select the customerid, firstname,
--    lastname, order_date, item, and price for everything each customer
--    purchased in the items_ordered table.
SELECT customers.customerid, customers.firstname, customers.lastname,
    items_ordered.order_date, items_ordered.item, items_ordered.price
FROM customers INNER JOIN items_ordered -- or FROM customers, items_ordered
ON customers.customerid = items_ordered.customerid;


-- 2. repeat ex 1, but display the results sorted by state in desc order
SELECT customers.customerid, customers.firstname, customers.lastname,
    items_ordered.order_date, items_ordered.item, items_ordered.price
FROM customers, items_ordered
WHERE customers.customerid = items_ordered.customerid -- ON doesnt work here
ORDER BY customers.state DESC;
