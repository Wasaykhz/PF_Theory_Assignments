## Question 2 — Elevator Simulation

### PAC Chart

| Section | Details |
|---|---|
| **Given Data** | Number of floor requests and the requested floor number for each request. The elevator starts at floor 0. |
| **Required Result** | Display whether the elevator is moving up, moving down, or opening doors for each request. |
| **Processing Required** | Compare the requested floor with the current floor. If the request is higher, print “Moving Up”. If it is lower, print “Moving Down”. If it is the same, print “Doors Opening”. Then update the current floor. |
| **Solution Alternatives** | Use `if-else if-else` statements to compare the requested floor with the current floor. A loop can be used to process all requests. |
