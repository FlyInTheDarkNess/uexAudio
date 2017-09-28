//
//  EUExAudioMgr.h
//  Appcan
//
//  Created by zywx on 11-8-26.
//  Copyright 2011 正益无线. All rights reserved.
//
#import "EUExBase.h"
#import "PFMusicPlayer.h"
#import <AudioToolbox/AudioToolbox.h>
#import "PMusicPlayer.h"

#define UEX_ERRORCALLBACK_AUDIO_DOACTION	@"操作失败"
#define UEX_ERRORCALLBACK_AUDIO_FILEPATH	@"文件路径错误"

#import <Foundation/Foundation.h>
#import  <MediaPlayer/MediaPlayer.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@class AudioPlayer;
@class AudioButton;
@class Recorder;
@interface EUExAudio : EUExBase <AVAudioRecorderDelegate,UIAlertViewDelegate,AVAudioPlayerDelegate,AVAudioSessionDelegate>{
	PFMusicPlayer *pfPlayer;
    //	SystemSoundID soundFileObject;
 	PMusicPlayer *musicPlayer;
	BOOL isAmr;
	NSString *amrPath;
	AVAudioRecorder *currentRecorder;
	int rType;
	NSString *recordFilePath;
    NSMutableDictionary *soundPoolDict;
    
    //onLine
    AudioPlayer *_audioPlayer;
    UIProgressView *  progresse;
    double currentTime;
    double totlesTime;
    NSTimer * musicTimer;
    AudioButton *  btnAudio ;
    BOOL isPlayed;
    
    UIView * backBoard;
    
    BOOL isNeedCloseTimerAutomatic;
    
    BOOL isNetResource;
    Recorder *recorder;
    
    //mp3
    AVAudioSession *session;
    NSURL *recordedFile;
    AVAudioPlayer *player;
    AVAudioRecorder *recordermp3;
    NSString *saveNameMp3;
    
}
@property (nonatomic , retain) AVPlayer *avPlayer;
@property (nonatomic , retain) NSURL *avURL;
@property (nonatomic , retain) AVAudioPlayer *player;
@property (nonatomic , retain) NSURL *recordedFile;
@property(nonatomic,retain) NSMutableDictionary *soundPoolDict;
@property(nonatomic,retain)AVAudioRecorder *currentRecorder;
@property(nonatomic,copy)	NSString *amrPath;
@property(nonatomic,copy)NSString *recordFilePath;
@property(nonatomic,assign)NSInteger runloopTime;
@property(nonatomic,retain)NSMutableDictionary *alert_Arguments;

@property(nonatomic, strong) AVAudioRecorder *recorderWav;
@property(nonatomic, strong) NSURL *recordTempFileURL;
@property (nonatomic)BOOL isRecordingWav;
@property(nonatomic, strong) NSString *saveNameWav;

@property(nonatomic,assign)NSInteger playTimes;

//@property (readonly)SystemSoundID  soundFileObject;
-(void)uexSuccessWithOpId:(int)inOpId dataType:(int)inDataType data:(NSString *)inData;

//onLine
@property(nonatomic,retain)UISlider * sliderse;
@property(nonatomic,retain)NSString * musicUrl;

@property(nonatomic,assign)int needCall;//播放模式:0为正常扩音器模式;1为听筒模式;
//光感，使用近距离传感器，当接近耳朵时，调用听筒模式，远离时采用功放模式（也可以自定义）
@property(nonatomic,assign)int isProximity;//是否开启感应，1为开启，0为关闭

@property(nonatomic,assign)BOOL isJudgeMc;//是否拥有麦克风权限

@end
