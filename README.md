# LeastWaitingTimeAlgo
1. Initialize Data Structures:
   - Initialize an empty list of available service providers.
   - Initialize an empty queue of users who need service.

2. Define Service Provider Data Structure:
   - Define the Service Provider structure with attributes:
     - ID (Unique identifier).
     - Workload (Current number of tasks they are handling).
     - EstimatedTime (Time estimated to complete a task based on historical data).
     - Availability (Availability status, e.g., busy or available).

3. Define User Data Structure:
   - Define the User structure with attributes:
     - ID (Unique identifier).
     - Timestamp (Time when they requested service).

4. Algorithm Steps:
   - When a user requests service:
     - Create a new User object with a unique ID and a timestamp.
     - Enqueue the user into the user queue.

   - To check the availability of service providers:
     - Iterate through the list of service providers.
     - Filter out providers who are currently marked as 'busy' or have exceeded their workload capacity.
     - Calculate the estimated time for each available provider to complete the task based on their historical data and workload.
     - Add available providers to the list of available service providers.

   - Sort the available service providers based on their estimated completion time in ascending order.

5. Assignment Loop:
   - Repeat the following loop until the user queue is empty:
     - Dequeue the next user from the user queue.
     - Check the list of available service providers (sorted by estimated completion time).
     - Assign the user to the service provider with the least estimated completion time.
     - Update the workload and availability status of the assigned service provider.
     - Record the assignment, including user ID, service provider ID, and the time of assignment.

6. Completion and User Feedback:
   - As service providers complete their tasks:
     - Update their workload by decrementing it.
     - Mark them as 'available' if their workload reaches zero.
     - Provide feedback to users about the estimated waiting time and the assigned service provider.

7. Monitor and Update:
   - Periodically (e.g., at fixed time intervals) monitor the workload and availability of service providers:
     - For each provider:
       - If their workload is zero and they are marked as 'busy', mark them as 'available' again.
       - If their workload exceeds a certain threshold, consider reassigning some tasks to other providers.

   - Reassign users to different providers if the initial assignment is no longer optimal due to changes in workload or availability.
