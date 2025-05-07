#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define DELAY() usleep(rand() % 2000000)

int ctrlCCount = 0;

void handleSigint(int sig) {
    if (ctrlCCount == 0) {
        ctrlCCount++;
        DELAY(); printf("\nCtrl+C detected. Press again to terminate Quantum CLI.\n");
        fflush(stdout);
    } else {
        DELAY(); printf("\nExiting Quantum CLI via quantum override. Goodbye.\n");
        usleep(1000000);
        exit(0);
    }
}

void printWelcome() {
    printf(
        " $$$$$$\\                                 $$\\                              $$$$$$\\\n"
        "$$  __$$\\                                $$ |                            $$  __$$\\\n"
        "$$ /  $$ |$$\\   $$\\  $$$$$$\\  $$$$$$$\\ $$$$$$\\   $$\\   $$\\ $$$$$$\\$$$$\\  $$ /  \\__|$$\\   $$\\ $$$$$$$\\   $$$$$$$\\\n"
        "$$ |  $$ |$$ |  $$ | \\____$$\\ $$  __$$\\\\_$$  _|  $$ |  $$ |$$  _$$  _$$\\ \\$$$$$$\\  $$ |  $$ |$$  __$$\\ $$  _____|\n"
        "$$ |  $$ |$$ |  $$ | $$$$$$$ |$$ |  $$ | $$ |    $$ |  $$ |$$ / $$ / $$ | \\____$$\\ $$ |  $$ |$$ |  $$ |$$ /\n"
        "$$ $$\\$$ |$$ |  $$ |$$  __$$ |$$ |  $$ | $$ |$$\\ $$ |  $$ |$$ | $$ | $$ |$$\\   $$ |$$ |  $$ |$$ |  $$ |$$ |\n"
        "\\$$$$$$ / \\$$$$$$  |\\$$$$$$$ |$$ |  $$ | \\$$$$  |\\$$$$$$  |$$ | $$ | $$ |\\$$$$$$  |\\$$$$$$$ |$$ |  $$ |\\$$$$$$$\\\n"
        " \\___$$$\\  \\______/  \\_______|\\__|  \\__|  \\____/  \\______/ \\__| \\__| \\__| \\______/  \\____$$ |\\__|  \\__| \\_______|\n"
        "     \\___|                                                                         $$\\   $$ |\n"
        "                                                                                   \\$$$$$$  |\n"
        "                                                                                    \\______/\n"
        "$$\\   $$\\                                                   $$\\\n"
        "$$ |  $$ |                                                  \\__|\n"
        "$$ |  $$ |$$\\   $$\\  $$$$$$\\   $$$$$$\\   $$$$$$\\ $$\\    $$\\ $$\\  $$$$$$$\\  $$$$$$\\   $$$$$$\\\n"
        "$$$$$$$$ |$$ |  $$ |$$  __$$\\ $$  __$$\\ $$  __$$\\\\$$\\  $$  |$$ |$$  _____|$$  __$$\\ $$  __$$\\ \n"
        "$$  __$$ |$$ |  $$ |$$ /  $$ |$$$$$$$$ |$$ |  \\__|\\$$\\$$  / $$ |\\$$$$$$\\  $$ /  $$ |$$ |  \\__| \n"
        "$$ |  $$ |$$ |  $$ |$$ |  $$ |$$   ____|$$ |       \\$$$  /  $$ | \\____$$\\ $$ |  $$ |$$ | \n"
        "$$ |  $$ |\\$$$$$$$ |$$$$$$$  |\\$$$$$$$\\ $$ |        \\$  /   $$ |$$$$$$$  |\\$$$$$$  |$$ | \n"
        "\\__|  \\__| \\____$$ |$$  ____/  \\_______|\\__|         \\_/    \\__|\\_______/  \\______/ \\__|\n"
        "          $$\\   $$ |$$ |\n"
        "          \\$$$$$$  |$$ |\n"
        "           \\______/ \\__|\n\n"
    );
    printf("Welcome to the Quantum Command Line Interface - Empowering CPUs since 2025.\n");
    printf("Type 'quantum help' to get started.\n\n");
}

void printHelp() {
    DELAY(); printf("All commands:\n");
    printf("  quantum start      - Activate Quantum Multithreading Mode\n");
    printf("  quantum init       - Initialize Quantum Entropy Field\n");
    printf("  quantum pulse      - Send Q-pulse to Hypernode\n");
    printf("  quantum rollback   - Revert quantum state to last stable configuration\n");
    printf("  quantum status     - Check quantum field integrity\n");
    printf("  quantum flux       - Realign particle probabilities\n");
    printf("  quantum end        - Exit Quantum CLI\n\n");
}

void runFakeQuantumCommand(const char* cmd) {
    if (strcmp(cmd, "quantum start") == 0) {
        DELAY(); printf("Activating Quantum Multithreading Mode...\n");
        for (int i = 0; i <= 100; i += rand() % 15) {
            DELAY(); printf("Progress: %3d%%\r", i);
            fflush(stdout);
            usleep(100000 + rand() % 100000);
        }
        DELAY(); printf("Progress: 100%%\n");
        DELAY(); printf("Quantum Core Synchronized.\n\n");
        int i = system("cd scripts && bash quantum_algo.sh");//; bash test.sh");
        printf("%d\n", i);

    } else if (strcmp(cmd, "quantum init") == 0) {
        DELAY(); printf("Initializing Quantum Entropy Field...\n");
        for (int i = 0; i < 5; i++) {
            DELAY(); printf("Entropy packet %d aligned.\n", i + 1);
            usleep(300000);
        }
        DELAY(); printf("Quantum Entropy Field Stabilized.\n\n");
    } else if (strcmp(cmd, "quantum pulse") == 0) {
        DELAY(); printf("Sending Q-pulse to Hypernode...\n");
        usleep(500000);
        DELAY(); printf("Pulse reflected from dimension 7-C. Phase shift detected.\n");
        usleep(500000);
        DELAY(); printf("Q-pulse loopback verified.\n\n");
    } else if (strcmp(cmd, "quantum rollback") == 0) {
        DELAY(); printf("Reverting quantum state to last stable configuration...\n");
        usleep(700000);
        DELAY(); printf("Undoing entanglement drift...\n");
        usleep(700000);
        DELAY(); printf("System restored to Temporal Snapshot #42.\n\n");
    } else if (strcmp(cmd, "quantum status") == 0) {
        DELAY(); printf("Quantum Field Status:\n");
        DELAY(); printf("   Entropy:       98%% stabilized\n");
        DELAY(); printf("   Flux Coherence: Optimal\n");
        DELAY(); printf("   Node Sync:     5/5 nodes online\n");
        DELAY(); printf("   Multiverse Drift: 0.0003π\n");
        DELAY(); printf("All systems nominal.\n\n");
    } else if (strcmp(cmd, "quantum flux") == 0) {
        DELAY(); printf("Realigning particle probabilities...\n");
        char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        for (int i = 0; i < 3; i++) {
            char buf[9] = {0};
            for (int j = 0; j < 8; j++) {
                buf[j] = chars[rand() % strlen(chars)];
            }
            DELAY(); printf("   Alignment code: %s\n", buf);
            usleep(300000);
        }
        DELAY(); printf("Probability waveforms normalized.\n\n");
    } else if (strcmp(cmd, "quantum cat") == 0){
        DELAY(); printf("The cat is a qubit. It both exists and doesn't.\n\n");
    }
}

int startsWith(const char *pre, const char *str) {
    return strncmp(pre, str, strlen(pre)) == 0;
}

void main() {
    srand(time(NULL));
    char input[256];
    signal(SIGINT, handleSigint);
    printWelcome();

    while (1) {
        DELAY(); printf(">> ");
        if (fgets(input, sizeof(input), stdin) == NULL) continue;

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "quantum end") == 0) {
            DELAY(); printf("Exiting Quantum CLI. Goodbye.\n");
            usleep(1000000);
            exit(0);
        } else if (strcmp(input, "quantum help") == 0) {
            printHelp();
        } else if (
            strcmp(input, "quantum start") == 0 ||
            strcmp(input, "quantum init") == 0 ||
            strcmp(input, "quantum pulse") == 0 ||
            strcmp(input, "quantum rollback") == 0 ||
            strcmp(input, "quantum status") == 0 ||
            strcmp(input, "quantum flux") == 0 ||
            strcmp(input, "quantum cat") == 0
        ) {
            runFakeQuantumCommand(input);
        } else if (strcmp(input, "quantum") == 0 || strcmp(input, "quantum ") == 0) {
            DELAY(); printf("Use 'quantum help' to show all available commands.\n\n");
        } else if (startsWith("quantum", input)) {
            DELAY(); printf("Invalid command. Try 'quantum help' to see all commands.\n\n");
        } else {
            DELAY(); printf("Invalid command. Commands start with 'quantum ...'. Use 'quantum help' to show all commands.\n\n");
        }
    }

    return;
}
