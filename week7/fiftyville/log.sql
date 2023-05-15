-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Theft took place on July 28
-- Theft took place on Humphrey Street

-- TABLES
-- airports              crime_scene_reports   people
-- atm_transactions      flights               phone_calls
-- bakery_security_logs  interviews
-- bank_accounts         passengers


-- Get the crime scene description
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Humphrey Street";
-- IMPORTANT INFO ABOUT THIS QUERY
    -- theft took place at 10:15am at the bakery
    -- littering took place at 16:36


-- Get transcript from interviews
SELECT transcript
FROM interviews
WHERE month = 7 AND day = 28;
-- IMPORTANT INFO ABOUT THIS QUERY
    -- 1st interview
    -- sometime within 10 minutes of the theft, someone saw the thief get into a car in the barery parking lot
        -- TODO (v) look at security footage from the parking lot for cars leaving the parking lot in that time frime

    -- 2nd interview
    -- person saw the thief withdrawing money from a ATM machine on Leggett Street, before the arriving at the bakery
        -- TODO (v) look at atm transactions

    -- 3rd interview
    -- he called someone for less than a minute, planning to take the earliest fligth out of the town. Then thief asked the person on the other side to purchase flight tickets
        -- TODO look at the earliest flight on day 29 month 7


--
-- Get plates of the cars leaving the bakery parking lot in the time frame of the crime
-- License plate of the thief
SELECT people.name, bakery_security_logs.license_plate
FROM bakery_security_logs
JOIN people ON bakery_security_logs.license_plate = people.license_plate
WHERE day = 28 AND month = 7 AND hour = 10 AND minute >= 15 AND minute <= 25;



--
-- Get ATM transactions before 10:15am, including amount, account number and transaction type
select people.name, atm_transactions.account_number from atm_transactions
join bank_accounts on atm_transactions.account_number = bank_accounts.account_number
join people on bank_accounts.person_id = people.id
where day = 28 and month = 7 and transaction_type = "withdraw" and atm_location = "Leggett Street";



--
-- Tracking call from the thief that took place right after the time
SELECT people.name, people.passport_number, phone_calls.caller
FROM phone_calls
JOIN people ON phone_calls.caller = people.phone_number
WHERE day = 28 AND month = 7 AND duration < 60;


-- Getting suspects phone number and name
SELECT people.name, phone_calls.receiver
FROM phone_calls
JOIN people ON phone_calls.receiver = people.phone_number
WHERE day = 28 AND month = 7 AND duration < 60;

-- airport stuff
select id, origin_airport_id, destination_airport_id, hour, minute from flights
where day = 29 and month = 7
order by hour asc limit 1;



select city from airports
where id = (select destination_airport_id from flights
    where month = 7 and day = 29 and origin_airport_id = (
        select id from airports where city = "Fiftyville"
    )
    order by hour, minute limit 1
);
