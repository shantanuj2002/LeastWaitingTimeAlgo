#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Service Provider Class
class ServiceProvider {
public:
    int id;
    int workload;
    bool available;
    double estimatedTime;

    ServiceProvider(int id, double estimatedTime) : id(id), workload(0), available(true), estimatedTime(estimatedTime) {}
};

// User Class
class User {
public:
    int id;
    double timestamp;
    double waitTime;

    User(int id, double timestamp) : id(id), timestamp(timestamp), waitTime(0.0) {}
};

// Custom comparison function for the priority queue
struct CompareProviders {
    bool operator()(const ServiceProvider& a, const ServiceProvider& b) {
        // Compare estimated completion time
        return a.estimatedTime > b.estimatedTime;
    }
};

int main() {
    // Create a list of service providers with estimated times
    vector<ServiceProvider> providers;
    providers.push_back(ServiceProvider(1, 20.0));
    providers.push_back(ServiceProvider(2, 15.0));
    providers.push_back(ServiceProvider(3, 10.0));

    // Create a user queue
    queue<User> userQueue;
    userQueue.push(User(101, 0.0));
    userQueue.push(User(102, 2.0));
    userQueue.push(User(103, 5.0));
    userQueue.push(User(104, 8.0));
    userQueue.push(User(105, 12.0));

    const double maxWaitTime = 15.0;  // Maximum allowed waiting time (adjust as needed)

    // Priority queue for available service providers
    priority_queue<ServiceProvider, vector<ServiceProvider>, CompareProviders> availableProviders;

    while (!userQueue.empty()) {
        User currentUser = userQueue.front();
        userQueue.pop();

        // Check if the user has exceeded the maximum waiting time
        if (currentUser.waitTime > maxWaitTime) {
            cout << "User " << currentUser.id << " has exceeded the maximum waiting time and is removed from the queue." << endl;
            continue;  // Skip this user
        }

        // Check for available providers
        while (!providers.empty()) {
            ServiceProvider provider = providers.back();
            providers.pop_back();

            if (provider.available && provider.workload == 0) {
                availableProviders.push(provider);
            }
        }

        if (!availableProviders.empty()) {
            // Assign the user to the provider with the least estimated time
            ServiceProvider assignedProvider = availableProviders.top();
            availableProviders.pop();

            // Update provider's workload and availability status
            assignedProvider.workload++;
            assignedProvider.available = false;

            cout << "User " << currentUser.id << " assigned to Service Provider " << assignedProvider.id << endl;
        } else {
            // No available providers, the user waits and increments their wait time
            currentUser.waitTime += 1.0;  // Increment wait time (you can adjust this as needed)
            userQueue.push(currentUser);   // Add the user back to the queue
        }
    }

    return 0;
}
