// Misc. : Simple Sounds
// Author: Michael Hall
//
// This program is available for download through our website XoaX.net with no guarantees.
// Disclaimer: While we have made every effort to ensure the quality of our content, all risks associated
// with downloading or using this solution, project and code are assumed by the user of this material.
//
// Copyright 2008 Xoax - For personal use only, not for distribution
#include <windows.h>
#include <vector>

enum EFrequency {
	keRest = 0,
	keC1 = 131, keCS1 = 139, keD1 = 147, keDS1 = 156, keE1 = 165, keF1 = 175,
	keFS1 = 185, keG1 = 196, keGS1 = 208, keA1 = 220, keAS1 = 233, keB1 = 247,
	keC2 = 262, keCS2 = 277, keD2 = 294, keDS2 = 311, keE2 = 330, keF2 = 349,
	keFS2 = 370, keG2 = 392, keGS2 = 415, keA2 = 440, keAS2 = 466, keB2 = 494,
	keC3 = 523, keCS3 = 554, keD3 = 587, keDS3 = 622, keE3 = 659, keF3 = 698,
	keFS3 = 740, keG3 = 784, keGS3 = 830, keA3 = 880, keAS3 = 932, keB3 = 988,
};
enum EDuration {
	ke16th = 100, ke8th = (ke16th << 1), keQuart = (ke8th << 1),
	keHalf = (keQuart << 1), keWhole = (keQuart << 1)
};

class CNote {
public:
	CNote(unsigned int uiFrequency, unsigned int uiDuration)
		: muiFrequency(uiFrequency), muiDuration(uiDuration) {}
	void Play () {
		if (muiFrequency > 0) {
			Beep(muiFrequency, muiDuration);
		} else {
			Sleep(muiDuration);
		}
	}
	unsigned int muiFrequency;
	unsigned int muiDuration;
};

class CMelody {
public:
	void AddNote(unsigned int uiFrequency, unsigned int uiDuration) {
		mqNotes.push_back(CNote(uiFrequency, uiDuration));
	}
	void Play () {
		const unsigned int kuiNoteCount = mqNotes.size();
		std::vector<CNote>::iterator qIter;
		for (qIter = mqNotes.begin(); qIter != mqNotes.end(); ++qIter) {
			qIter->Play();
		}
	}
    
	std::vector<CNote> mqNotes;
};


void Melodia1(CMelody& qSilentNight){
	qSilentNight.AddNote(keCS2, ke8th);
    qSilentNight.AddNote(keCS2, ke8th);
	qSilentNight.AddNote(keRest, ke8th);
    qSilentNight.AddNote(keCS2, ke8th);
    qSilentNight.AddNote(keAS1, keQuart);
    qSilentNight.AddNote(keGS1, keQuart);
}

void Melodia2(CMelody& qSilentNight){
	qSilentNight.AddNote(keG1, ke8th);
    qSilentNight.AddNote(keG1, ke8th);
	qSilentNight.AddNote(keRest, ke8th);
    qSilentNight.AddNote(keG1, ke8th);
    qSilentNight.AddNote(keAS1, keQuart);
    qSilentNight.AddNote(keCS2, keQuart);
}

void Melodia3(CMelody& qSilentNight){
	qSilentNight.AddNote(keCS2, ke8th);
    qSilentNight.AddNote(keCS2, ke8th);
	qSilentNight.AddNote(keRest, ke8th);
    qSilentNight.AddNote(keCS2, ke8th);
    qSilentNight.AddNote(keGS1, ke8th);
    qSilentNight.AddNote(keGS1, ke8th);
	qSilentNight.AddNote(keRest, ke8th);
    qSilentNight.AddNote(keGS1, ke8th);

    qSilentNight.AddNote(keAS1, ke8th);
    qSilentNight.AddNote(keAS1, ke8th);
	qSilentNight.AddNote(keRest, ke8th);
    qSilentNight.AddNote(keAS1, ke8th);
    qSilentNight.AddNote(keC2, ke8th);
    qSilentNight.AddNote(keC2, ke8th);
	qSilentNight.AddNote(keRest, ke8th);
    qSilentNight.AddNote(keC2, ke8th);
}
void Melodia4(CMelody& qSilentNight){
	qSilentNight.AddNote(keAS1, ke8th);
    qSilentNight.AddNote(keAS1, ke8th);
	qSilentNight.AddNote(keRest, ke8th);
    qSilentNight.AddNote(keAS1, ke8th);
    qSilentNight.AddNote(keC2, ke8th);
    qSilentNight.AddNote(keC2, ke8th);
	qSilentNight.AddNote(keRest, ke8th);
    qSilentNight.AddNote(keC2, ke8th);

    qSilentNight.AddNote(keGS1, ke8th);
    qSilentNight.AddNote(keGS1, ke8th);
	qSilentNight.AddNote(keRest, ke8th);
    qSilentNight.AddNote(keGS1, ke8th);
    qSilentNight.AddNote(keCS2, ke8th);
    qSilentNight.AddNote(keCS2, ke8th);
	qSilentNight.AddNote(keRest, ke8th);
    qSilentNight.AddNote(keCS2, ke8th);
}

void Melodia5(CMelody& qSilentNight){
	qSilentNight.AddNote(keCS1, ke8th);
    qSilentNight.AddNote(keCS1, ke8th);
	qSilentNight.AddNote(keCS1, ke8th);
    qSilentNight.AddNote(keCS1, ke8th);
    
}