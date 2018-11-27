//
//  SGFFTools.h
//  SGPlayer
//
//  Created by Single on 19/01/2017.
//  Copyright © 2017 single. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "avformat.h"

typedef NS_ENUM(NSUInteger, SGFFDecoderErrorCode) {
    SGFFDecoderErrorCodeFormatCreate,
    SGFFDecoderErrorCodeFormatOpenInput,
    SGFFDecoderErrorCodeFormatFindStreamInfo,
    SGFFDecoderErrorCodeStreamNotFound,
    SGFFDecoderErrorCodeCodecContextCreate,
    SGFFDecoderErrorCodeCodecContextSetParam,
    SGFFDecoderErrorCodeCodecFindDecoder,
    SGFFDecoderErrorCodeCodecVideoSendPacket,
    SGFFDecoderErrorCodeCodecAudioSendPacket,
    SGFFDecoderErrorCodeCodecVideoReceiveFrame,
    SGFFDecoderErrorCodeCodecAudioReceiveFrame,
    SGFFDecoderErrorCodeCodecOpen2,
    SGFFDecoderErrorCodeAuidoSwrInit,
};

#pragma mark - Log Config

#define SGWeakSelf __weak typeof(self) weakSelf = self;
#define SGStrongSelf __strong typeof(weakSelf) strongSelf = weakSelf;

// log level
#ifdef DEBUG
#define ZYPlayerLog(...) NSLog(__VA_ARGS__)
#else
#define ZYPlayerLog(...)
#endif

#pragma mark - Util Function

void ZYLog(void * context, int level, const char * format, va_list args);

NSError * ZYCheckError(int result);
NSError * ZYCheckErrorCode(int result, NSUInteger errorCode);

double ZYStreamGetTimebase(AVStream * stream, double default_timebase);
double ZYStreamGetFPS(AVStream * stream, double timebase);

NSDictionary * ZYFoundationBrigeOfAVDictionary(AVDictionary * avDictionary);
AVDictionary * ZYFFmpegBrigeOfNSDictionary(NSDictionary * dictionary);
