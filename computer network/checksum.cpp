#include <bits/stdc++.h>
using namespace std;


string Ones_complement(string data)
{
	for (int i = 0; i < data.length(); i++) {
		if (data[i] == '0')
			data[i] = '1';
		else
			data[i] = '0';
	}

	return data;
}

string checkSum(string data, int block_size)
{

    int n = data.length();

	string result = "";

	for (int i = 0; i < block_size; i++) {
		result += data[i];
	}

    cout << "\nData Block: " << result;

	for (int i = block_size; i < n; i += block_size) {
		string next_block = "";

		for (int j = i; j < i + block_size; j++) {
			next_block += data[j];
		}

		cout << "\nData Block: " << next_block;

		string additions = "";
		int sum = 0, carry = 0;

		for (int k = block_size - 1; k >= 0; k--) {
			sum += (next_block[k] - '0') + (result[k] - '0');
			carry = sum / 2;
			if (sum == 0) {
				additions = '0' + additions;
				sum = carry;
			}
			else if (sum == 1) {
				additions = '1' + additions;
				sum = carry;
			}
			else if (sum == 2) {
				additions = '0' + additions;
				sum = carry;
			}
			else {
				additions = '1' + additions;
				sum = carry;
			}
		}

		string final = "";

		if (carry == 1) {
			for (int l = additions.length() - 1; l >= 0;
				l--) {
				if (carry == 0) {
					final = additions[l] + final;
				}
				else if (((additions[l] - '0') + carry) % 2
						== 0) {
					final = "0" + final;
					carry = 1;
				}
				else {
					final = "1" + final;
					carry = 0;
				}
			}

			result = final;
		}
		else {
			result = additions;
		}
	}

	cout << "\nChecksum  : " << Ones_complement(result);
	return Ones_complement(result);
}

int main()
{
    cout << "Sender's Side" << endl;
	string sent_message;
	cout << "\nEnter the message to be sent (Block size = 8): ";
	cin >> sent_message;
	string recv_message = "";
	int block_size = 8;

    string sender_checksum = checkSum(sent_message, block_size);

    cout << "\n\nSent message: " << sent_message + sender_checksum;

    cout << "\n\nReceiver's Side" << endl;

    cout << "\nReceived message: " << sent_message + sender_checksum << endl;
    string receiver_checksum = checkSum(sent_message + sender_checksum, block_size);

	if (count(receiver_checksum.begin(), receiver_checksum.end(), '0') == block_size){
		cout << "\n\nNo Error" << endl;
	}
	else {
		cout << "\n\nError";
	}

	return 0;
}