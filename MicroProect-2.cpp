#include<iostream>
#include<windows.h>  
#include<mmsystem.h>
#include<string>
#include<vector>
using namespace std;

class Song {
public:
    string fileName;
    string title;
    string artist;
    Song(string a, string b, string c){
        fileName = a;
        title = b;
        artist = c;
    }
};

class MusicPlayer {
private:
    vector<Song> playlist;
    int currentIndex;
public:
    MusicPlayer() : currentIndex(-1) {}
    void addSong(string file, string title, string artist) {
        playlist.push_back(Song(file, title, artist));
    }
    bool play(int index) {
        if (index >= 0 && index < (int)playlist.size()) {
            currentIndex = index;
            PlaySound(playlist[index].fileName.c_str(), NULL, SND_FILENAME | SND_ASYNC);
            return true;
        }
        return false;
    }
    void stop() {
        PlaySound(NULL, NULL, 0);
        currentIndex = -1;
    }
    void next() {
        if (!playlist.empty()) {
            int nextIndex = (currentIndex + 1) % playlist.size();
            play(nextIndex);
        }
    }
    void previous() {
        if (!playlist.empty()) {
            int prevIndex = (currentIndex - 1 + playlist.size()) % playlist.size();
            play(prevIndex);
        }
    }
    string CurrentSongInfo() {
        if (currentIndex >= 0 && currentIndex < (int)playlist.size()) {
            return playlist[currentIndex].title + " -- " + playlist[currentIndex].artist;
        }
        return "No song loaded";
    }
    int getPlaylistSize() { return (int)playlist.size(); }
    int getCurrentIndex() { return currentIndex; }
};

int main() {
    MusicPlayer player;
        player.addSong("C:\\Users\\rites\\Downloads\\songs\\Boyfriend.wav" , "Boyfriend" , "Karan Aujla");
        player.addSong("C:\\Users\\rites\\Downloads\\songs\\attention.wav" , "Attention" , "Charlie Puth" );
        player.addSong("C:\\Users\\rites\\Downloads\\songs\\zulfein.wav", "Zulfein" , "DJ AYnik");
    int choice;
    do {
        cout << "\n=== Music Player ===\n";
        cout << "1. Play first song\n";
        cout << "2. Next song\n";
        cout << "3. Previous song\n";
        cout << "4. Stop\n";
        cout << "5. Show current song\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: player.play(0); break;
            case 2: player.next(); break;
            case 3: player.previous(); break;
            case 4: player.stop(); break;
            case 5: cout << player.CurrentSongInfo() << endl; break;
            case 0: break;  
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0; }
