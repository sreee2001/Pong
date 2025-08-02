#include "Direct3D.h"

// Create Direct3D and the Direct3D Device
void Direct3D::Initialize(GameWindow & gw)
{
    d3d = Direct3DCreate9(D3D_SDK_VERSION);

    ZeroMemory(&d3dpp, sizeof(d3dpp));

    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
    d3dpp.Windowed = gw.Windowed;
    d3dpp.BackBufferWidth = gw.Width;
    d3dpp.BackBufferHeight = gw.Height;

    d3d->CreateDevice(D3DADAPTER_DEFAULT,
                      D3DDEVTYPE_HAL,
                      gw.hWnd,
                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                      &d3dpp,
                      &d3ddev);

    D3DXCreateSprite(d3ddev, &d3dspt);
}

// Close the Device and Direct3D
void Direct3D::Close()
{
    d3ddev->Release();
    d3d->Release();
}

// Start rendering
void Direct3D::StartRender()
{
    d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
    d3ddev->BeginScene();
    d3dspt->Begin(D3DXSPRITE_ALPHABLEND);
}

// Stop rendering
void Direct3D::EndRender()
{
    d3dspt->End();
    d3ddev->EndScene();
    d3ddev->Present(NULL, NULL, NULL, NULL);

}

// Load a graphic into a Sprite object
void Direct3D::LoadSprite(Sprite & sprite, LPCTSTR File, int width, int height, int cols, int rows)
{
    D3DXCreateTextureFromFileEx(d3ddev,
                                File,
                                D3DX_DEFAULT,
                                D3DX_DEFAULT,
                                D3DX_DEFAULT,
                                NULL,
                                D3DFMT_A8R8G8B8,
                                D3DPOOL_MANAGED,
                                D3DX_DEFAULT,
                                D3DX_DEFAULT,
                                D3DCOLOR_XRGB(255, 0, 255),
                                NULL,
                                NULL,
                                & (sprite.tex));

    sprite.width = width;
    sprite.height = height;
    sprite.cols = cols;
    sprite.rows = rows;
}

// Draw a frame from a Sprite object
void Direct3D::DrawSprite(Sprite & sprite, int Frame, float x, float y, float z)
{
    RECT FrameBox;
    FrameBox.left = (Frame % sprite.cols) * sprite.width;
    FrameBox.top = (Frame / sprite.cols) * sprite.height;
    FrameBox.right = FrameBox.left + sprite.width;
    FrameBox.bottom = FrameBox.top + sprite.height;

    D3DXVECTOR3 position(x, y, z);

    d3dspt->Draw(sprite.tex, &FrameBox, NULL, &position, D3DCOLOR_XRGB(255, 255, 255));
}