#pragma once
#include "ofMain.h"
#include "ofxSecondWindow.h"
#include "ofxLayerMask.h"
#include "CanvasContents.h"
#include "MaskFrame.h"
#include "TextArea.h"
#include "Xml.h"
#include "Presets.h"
#include "Mouse.h"

class ofxProjectionMask{
public:
    void setup(StretchMode _stretchMode=STRETCH_TO_MASKFRAME, PresetMode presetMode=PRESETS_DEVELOPMENT);
    ofxLayerMask* newPattern(int width, int height);
    void layout();
    void update(int mouseX, int mouseY);
    void draw();
    
    void keyReleased(int key);
    void mouseDragged();
    void mousePressed();
    void mouseReleased();
    
    void setVolumes(float *volume, vector<float> *nonPlaybackVolumes);
    ofxLayerMask* nextPattern();

protected:
    Presets presets;
    DisplayMode displayMode;
    StretchMode stretchMode;
    
    ofxSecondWindow secondWindow;
    Canvas designCanvas, liveCanvas;
    CanvasContents canvasContents;
    vector<ofxLayerMask*> patterns;

    Mouse mouse;
    MaskFrame *selectedMaskFrame;
    TextArea textArea;
    Xml xml;
    
    void undo();
    void redo();
    
    void nudge(Direction direction);
    void toggleFrameNudge();
    
    void createNewMaskFrame();
    void createNewMaskPoint();
    void deleteHighlightedItem();
    
    void cycleMode();
    bool mouseIsOverDesignCanvas();
    
    void drawLiveCursor();
    void drawBufferPreviews();
    
    bool isTransforming();
};