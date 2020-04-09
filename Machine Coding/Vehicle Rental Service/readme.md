# Vehicle Rental Service

## Description
Flipkart is starting a new vehicle rental service called FlipKar. In this service, we will rent out different kinds of vehicles such as cars and bikes.

## Features
1. Rental service has multiple branches throughout the city.
2. Each branch has a limited number of different kinds of vehicles.
3. Each vehicle can be booked with the predefined price per unit time slot. For simplicity, the current pricing model does not support dynamic pricing or update on prices based on seasonality.
4. Each vehicle can be booked in multiples of 1-hour time slot.
5. Booking could be made only for the future Time and Date.

## Requirements
1. Onboard a new branch with the available vehicles.
2. Onboard new vehicle(s) of an existing type to a particular branch.
3. Rent vehicle for a time slot and a vehicle type (lowest price as the default choice of selection of vehicle, this should be extendable to any other strategy and should be configurable).
	i. Implementation should be pluggable for one or more strategy.
	ii. While booking if more than one vehicle is suitable for current strategy then selection should fallback on next strategy. E.g. lowest_price followed by vehicle_type etc.
	iii. For example, let’s say there are more than one type of vehicle available for given no. of passenger, then selection can be based on lowest price first and next is the type of vehicle where Sedan is better than Hatchback (Both of them are 5 seaters).
4. A system view should be made available, such as currently blocked vehicles, available vehicles of all the branches.

## Bonus question (good to have, only if required expectations are met):
1. Customer should be able to cancel a booking
2. Customer should be suggested the nearest branch as per his/her requirements (time slot and vehicle type)

## Other Notes:
1. Do NOT use any database or NoSQL store, use in-memory data-structure for now.
2. Do NOT create any UI for the application.
3. Have a driver class for demoing the execution of all the commands and come up with test cases.
4. Please prioritize code compilation, execution and completion.
5. Work on the expected output first and then add good-to-have features of your own.

## Expectations:
1. Make sure that you have working and demonstrable code.
2. Make sure that code is functionally correct and complete.
3. The code should be extensible to accommodate new requirements like vehicle selection strategy preference etc.
4. Make sure concurrent requests are handled appropriately.
5. The code should be modular, testable, readable and have right abstractions wherever required.

## Test cases:
## (Test-cases are defined for understanding feature requirements only. Please model it appropriately based on your service implementation)
* Suv - 7 Seater, Sedan - 5 Seater, Hatchback - 5 Seater.
* add_branch(‘koramangala’, [“1 suv for Rs.12 per hour”, “3 sedan for Rs.10 per hour”, “3 bikes for Rs.20 per hour”]);
* add_branch(‘jayanagar’, [“3 sedan for Rs.11 per hour”, “3 bikes for Rs.30 per hour”, “4 hatchback for Rs.8 per hour”]);
* add_branch(‘malleshwaram’, [“1 suv for Rs.11 per hour”, “1 sedan for Rs.10 per hour”, “2 hatchback for Rs.10 per hour”]);
* add_vehicle(‘koramangala’,  “1 sedan”); //add 1 sedan to koramangala
* rent_vehicle(‘5 Seater’, malleshwaram, 20th Feb 10:00 PM, 20th Feb 12:00 PM); //should book 1 sedan from malleshwaram. (as preference for sedan is greater than hatchback).
* rent_vehicle(‘5 Seater’, malleshwaram, 20th Feb 10:00 PM, 20th Feb 12:00 PM); //should book 1 Hatchback from malleshwaram. (as no Sedan is available).
* rent_vehicle(‘7 Seater’, ‘koramangala’, 20th Feb 10:00 PM, 20th Feb 12:00 PM);
//should book 1 suv from ‘koramangala’.
* rent_vehicle(‘7 Seater’, ‘koramangala’, 20th Feb 10:00 PM, 20th Feb 12:00 PM); //Should fail saying no vehicle.

* print_system_view_for_time_slot(20th Feb 11:00 PM, 20th Feb 12:00 PM):
	* Output:
		* ‘Koramangala’:
			* All “suv” are booked.
			* “sedan” is available for Rs.10
			* “bike” is available for Rs.20
		* ‘Jayanagar’:
			* “sedan” is available for Rs.11
			* “bike” is available for Rs.30
			* “hatchback” is available for Rs.8
		* ‘‘Malleshwaram’’:
			* “suv” is available for Rs. 11
			* All “sedan” are booked.
			* “hatchback” is available for Rs.10
