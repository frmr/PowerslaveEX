//
// Copyright(C) 2014-2015 Samuel Villarreal
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//      Game logic
//

#include "kexlib.h"
#include "renderMain.h"
#include "game.h"
#include "titlescreen.h"
#include "localization.h"

static kexGame gameLocal;
kexGame *kex::cGame = &gameLocal;

//
// kexGame::kexGame
//

kexGame::kexGame(void)
{
    this->smallFont = NULL;
    this->bigFont   = NULL;
    this->ticks     = 0;

    this->titleScreen = new kexTitleScreen;
    this->translation = new kexTranslation;
}

//
// kexGame::~kexGame
//

kexGame::~kexGame(void)
{
    delete titleScreen;
    delete translation;
}

//
// kexGame::Init
//

void kexGame::Init(void)
{
    smallFont   = kexFont::Alloc("smallfont");
    bigFont     = kexFont::Alloc("bigfont");

    titleScreen->Init();
    translation->Init();
}

//
// kexGame::Tick
//

void kexGame::Tick(void)
{
    titleScreen->Tick();
    ticks++;
}

//
// kexGame::Draw
//

void kexGame::Draw(void)
{
    titleScreen->Draw();
}

//
// kexGame::ProcessActions
//

void kexGame::ProcessActions(inputEvent_t *ev)
{
    switch(ev->type)
    {
    case ev_keydown:
        kex::cActions->ExecuteCommand(ev->data1, false);
        break;

    case ev_keyup:
        kex::cActions->ExecuteCommand(ev->data1, true);
        break;
    }
}

//
// kexGame::ProcessInput
//

bool kexGame::ProcessInput(inputEvent_t *ev)
{
    if(titleScreen->ProcessInput(ev))
    {
        return true;
    }

    return false;
}

//
// kexGame::DrawSmallString
//

void kexGame::DrawSmallString(const char *string, float x, float y, float scale, bool center,
                              byte r, byte g, byte b)
{
    kexRender::cBackend->SetBlend(GLSRC_SRC_ALPHA, GLDST_ONE_MINUS_SRC_ALPHA);
    smallFont->DrawString(string, x+1, y+1, scale, center, RGBA(0, 0, 0, 0xff));
    smallFont->DrawString(string, x, y, scale, center, RGBA(r, g, b, 0xff));
}

//
// kexGame::DrawBigString
//

void kexGame::DrawBigString(const char *string, float x, float y, float scale, bool center,
                            byte r, byte g, byte b)
{
    kexRender::cBackend->SetBlend(GLSRC_SRC_ALPHA, GLDST_ONE_MINUS_SRC_ALPHA);
    bigFont->DrawString(string, x+1, y+1, scale, center, RGBA(0, 0, 0, 0xff));
    bigFont->DrawString(string, x, y, scale, center, RGBA(r, g, b, 0xff));
}
