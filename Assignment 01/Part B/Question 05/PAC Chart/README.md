## Question 5 — Smart Campus Parking

### PAC Chart

| Section | Details |
|---|---|
| **Given Data** | User category, vehicle type, permit status, and emergency status. Parking zones are A (Faculty), B (Students), and C (Visitors) with capacities of 20, 40, and 15 respectively. |
| **Required Result** | Accept or reject each vehicle, assign a suitable parking zone, and display the final parking summary including occupancy and vehicle counts. |
| **Processing Required** | Validate all entered information. Check the user's category, vehicle type, permit, emergency status, and available space. Assign the vehicle to the appropriate zone according to the given rules. A car or bike uses 1 space, while a van uses 2 spaces. Maintain occupancy and accepted/rejected counters. |
| **Solution Alternatives** | Use nested `if-else` statements to handle user and vehicle combinations. Use loops to process multiple vehicles and variables to maintain zone occupancy and counters. |
