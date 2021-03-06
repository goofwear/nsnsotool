// Copyright (c) 2018, CBH <maodatou88@163.com>
// Licensed under the terms of the BSD 3-Clause License
// https://github.com/0CBH0/nsnsotool/blob/master/LICENSE

#pragma once

#define SHA256_ROTL(a,b) (((a>>(32-b))&(0x7fffffff>>(31-b)))|(a<<b))
#define SHA256_SR(a,b) ((a>>b)&(0x7fffffff>>(b-1)))
#define SHA256_Ch(x,y,z) ((x&y)^((~x)&z))
#define SHA256_Maj(x,y,z) ((x&y)^(x&z)^(y&z))
#define SHA256_E0(x) (SHA256_ROTL(x,30)^SHA256_ROTL(x,19)^SHA256_ROTL(x,10))
#define SHA256_E1(x) (SHA256_ROTL(x,26)^SHA256_ROTL(x,21)^SHA256_ROTL(x,7))
#define SHA256_O0(x) (SHA256_ROTL(x,25)^SHA256_ROTL(x,14)^SHA256_SR(x,3))
#define SHA256_O1(x) (SHA256_ROTL(x,15)^SHA256_ROTL(x,13)^SHA256_SR(x,10))

typedef unsigned char	u8;
typedef unsigned short	u16;
typedef unsigned int	u32;
typedef signed   char	s8;
typedef signed   short	s16;
typedef signed   int    s32;
typedef unsigned long	ulg;
typedef unsigned long long u64;
typedef signed long long   s64;

u8  tempa_u8,
    tempb_u8;

u16 tempa_u16,
    tempb_u16;

u32 tempa_u32,
    tempb_u32;

ulg pos;

typedef struct {
	u32 magic;
	u32 version;
	u32 pada;
	u32 flags;
	u32 fileOffset_text;
	u32 memoryOffset_text;
	u32 dcmpSize_text;
	u32 modOffset;
	u32 fileOffset_rodata;
	u32 memoryOffset_rodata;
	u32 dcmpSize_rodata;
	u32 modSize;
	u32 fileOffset_data;
	u32 memoryOffset_data;
	u32 dcmpSize_data;
	u32 bssSize;
	char note[0x20];
	u32 cmpSize_text;
	u32 cmpSize_rodata;
	u32 cmpSize_data;
	char padb[0x1C];
	u32 rdOffset_api;
	u32 rdSize_api;
	u32 rdOffset_dynstr;
	u32 rdSize_dynstr;
	u32 rdOffset_dynsym;
	u32 rdSize_dynsym;
} NSOHeader;

void sha256_nso(char *data, long length, u32 *sha256);
int fcopy(char *src_name, char *dest_name);

int decompress(FILE *in, FILE *out);
int compress(FILE *in, FILE *out);
