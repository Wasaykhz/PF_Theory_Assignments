## Question 3 — Class Result Processing

### PAC Chart

| Section | Details |
|---|---|
| **Given Data** | Number of students and marks of 5 subjects for each student. |
| **Required Result** | Calculate the average and display the result as Distinction, Pass, or Fail. If any subject mark is below 33, display “Fail — Subject Deficiency”. |
| **Processing Required** | Add the 5 subject marks and divide by 5 to find the average. If any subject mark is below 33, the student fails due to subject deficiency. Otherwise, average ≥ 80 gives Distinction, average ≥ 60 gives Pass, and average below 60 gives Fail. |
| **Solution Alternatives** | Use nested `for` loops to process all students and their 5 subjects. Use `if-else` statements to determine the final result. |
