## Question 6 — Smart EV Charging/Parking

### PAC Chart

| Section | Details |
|---|---|
| **Given Data** | Vehicle type, current battery percentage, required charge percentage, parking duration, current time, membership status, disabled priority status, and charging station availability. |
| **Required Result** | Determine charging eligibility and priority, calculate charging and parking costs, apply applicable discounts, and display the final payable amount and relevant message. |
| **Processing Required** | Check whether charging is available and whether the vehicle qualifies for charging. Calculate the required charging amount. Determine Emergency, Priority, or Normal charging priority. Check peak or off-peak time and apply the appropriate charging rate and discounts. Calculate parking charges according to parking duration and apply membership or disabled-priority rules. |
| **Solution Alternatives** | Use nested `if-else` statements for vehicle, charging, priority, time, and parking conditions. Use separate variables for charging cost, parking cost, discounts, and final payable amount. |
