#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> positiveWords = {"good", "happy", "love", "awesome", "great", "excellent", "amazing"};
    vector<string> negativeWords = {"bad", "sad", "hate", "terrible", "awful", "worst", "angry"};

    string input;
    cout << "Enter a sentence to analyze emotion:\n";
    getline(cin, input);

    // Convert to lowercase
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    stringstream ss(input);
    string word;
    int positiveCount = 0, negativeCount = 0;

    while (ss >> word) {
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end()); // remove punctuation

        if (find(positiveWords.begin(), positiveWords.end(), word) != positiveWords.end()) {
            positiveCount++;
        } else if (find(negativeWords.begin(), negativeWords.end(), word) != negativeWords.end()) {
            negativeCount++;
        }
    }

    cout << "\nPositive words: " << positiveCount;
    cout << "\nNegative words: " << negativeCount;

    cout << "\n\nEmotion Analysis: ";
    if (positiveCount > negativeCount)
        cout << "😊 Positive Vibes Detected!";
    else if (negativeCount > positiveCount)
        cout << "😞 Negative Tone Detected!";
    else
        cout << "😐 Neutral Emotion.";

    cout << endl;
    return 0;
}
