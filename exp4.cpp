#include <bits/stdc++.h>
using namespace std;


bool send(int frame) {
    int chance = rand() % 10;  
    if (chance < 3) { 
        cout << "Frame " << frame << " lost or corrupted. Retransmitting...\n";
        return false;
    }
    cout << "Frame " << frame << " sent successfully.\n";
    return true;
}

bool ACK(int frame) {
    int chance = rand() % 10;
    if (chance < 3) { 
        cout << "ACK for frame " << frame << " lost. Retransmitting frame...\n";
        return false;
    }
    cout << "ACK " << frame << " received.\n";
    return true;
}

void ARQ(int totalFrames, int timeout) {
    for (int frame = 1; frame <= totalFrames; frame++) {
        bool sent = false, ackReceived = false;

        while (!(sent&&ackReceived)) {
            sent = send(frame);
            if (sent==false) continue; 
4

            this_thread::sleep_for(chrono::milliseconds(timeout));

            ackReceived = ACK(frame);
        }
    }
    cout << "All frames transmitted successfully!\n";
}

int main() {
    srand(time(0));

    int totalFrames;
    cout << "Enter number of frames to send: ";
    cin >> totalFrames;

    int timeout;
    cout<<"Enter timeout"<<endl;
    cin>>timeout;

    ARQ(totalFrames, timeout);

    return 0;
}
