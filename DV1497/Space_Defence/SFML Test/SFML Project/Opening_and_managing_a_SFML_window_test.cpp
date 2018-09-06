#include <SFML/Window.hpp>
#include<iostream>

using namespace std;
using namespace sf;

int main()
{
	//Style 4 : close + resize
	//Style 5 : close + resize + minimise
	VideoMode videoMode;
	int choice = 0;
	vector<VideoMode> resolutionList(videoMode.getFullscreenModes());
	for (int i = 0; i < resolutionList.size(); i++)
	{
		cout << i << ": " << resolutionList[i].height << "X" << resolutionList[i].width << endl;
	}
	cout << "\nPick resolution: ";
	cin >> choice;
	cin.clear();
	cin.ignore();
	videoMode = resolutionList[choice];
	Window window(videoMode, "New window", Style::Close);
	window.setVerticalSyncEnabled(true);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
		}
	}
	return 0;
}