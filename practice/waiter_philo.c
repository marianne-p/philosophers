#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_mutex_t waiter;

void* philosopher(void* num);

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_numbers[NUM_PHILOSOPHERS];

    // Initialize the waiter mutex
    pthread_mutex_init(&waiter, NULL);

    // Initialize the fork mutexes
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_numbers[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_numbers[i]);
    }

    // Join philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Clean up
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }
    pthread_mutex_destroy(&waiter);

    return 0;
}

void* philosopher(void* num) {
    int id = *(int*)num;
    int leftFork = id;
    int rightFork = (id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // Thinking
        printf("Philosopher %d is thinking.\n", id);
        sleep(1 + rand() % 2);  // Think for 1-2 seconds

        // Ask permission to eat
        pthread_mutex_lock(&waiter);
        printf("Philosopher %d asks for permission to eat.\n", id);

        // Pick up forks
        pthread_mutex_lock(&forks[leftFork]);
        pthread_mutex_lock(&forks[rightFork]);

        pthread_mutex_unlock(&waiter);

        // Eating
        printf("Philosopher %d is eating.\n", id);
        sleep(1 + rand() % 2);  // Eat for 1-2 seconds

        // Put down forks
        pthread_mutex_unlock(&forks[leftFork]);
        pthread_mutex_unlock(&forks[rightFork]);

        // Back to thinking
    }

    return NULL;
}

