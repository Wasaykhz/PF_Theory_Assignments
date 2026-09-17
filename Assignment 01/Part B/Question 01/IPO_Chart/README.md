## Question 1 — Hotel Booking System

### IPO Chart

| Input | Process | Output |
|---|---|---|
| Number of guests | Select rate according to season and room type | Final price for each guest |
| Season | Calculate room cost | Total hotel revenue |
| Room type | Check stay duration | |
| Number of nights | Apply 15% discount if nights > 7 | |

### PAC Chart

| Section | Details |
|---|---|
| **Given Data** | Number of guests, season (Peak/Off-Peak), room type (Standard/Deluxe/Suite), number of nights. |
| **Required Result** | Final price for each guest and total hotel revenue. |
| **Processing Required** | Determine the room rate from the season and room type. Calculate rate × nights. If nights are greater than 7, apply the 15% discount. |
| **Solution Alternatives** | Use nested `if-else` statements for season and room type. A `switch` statement can also be used for room type. |
