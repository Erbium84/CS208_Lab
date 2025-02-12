#include <bits/stdc++.h>

using namespace std;
bool isPacketLost() {
    return rand() % 5 == 0; 
}

bool isNegativeAck() {
    return rand() % 7 == 0; 
}

void sender(int df, int ws, int timeout) {
    int base = 0;
    int next_seq_num = 0;
    vector<bool> acked(df, false);

    cout << "Starting Go-Back-N ARQ Protocol...\n";

    while (base < df) {
        while (next_seq_num < base + ws && next_seq_num < df) {
            cout << "Sending packet " << next_seq_num << endl;
            next_seq_num++;
        }

        this_thread::sleep_for(chrono::seconds(timeout));

        for (int i = base; i < next_seq_num; ++i) {
            if (!acked[i]) {
                if (isPacketLost()) {
                    cout << "timeout: No ACK for packet " << i << ". Retransmitting from packet " << base << endl;
                    next_seq_num = base; 
                    break;
                } else if (isNegativeAck()) {
                    cout << "NAK received for packet " << i << ". Retransmitting from packet " << i << endl;
                    next_seq_num = i; 
                    break;
                } else {
                    cout << "ACK received for packet " << i << endl;
                    acked[i] = true;
                    base++;
                }
            }
        }
    }

    cout << "All packets successfully sent and acknowledged!\n";
}

int main() {
    srand(time(0));
    int df, ws, timeout;
    cout<<"Enter number of frames: ";
    cin>>df;
    cout<<"Enter window size: ";
    cin>>ws;
    cout<<"Enter timeout in second: ";
    cin>>timeout;
    sender(df, ws, timeout);
    return 0;
}
