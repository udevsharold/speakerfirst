//    Copyright (c) 2021 udevs
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, version 3.
//
//    This program is distributed in the hope that it will be useful, but
//    WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
//    General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program. If not, see <http://www.gnu.org/licenses/>.

@interface TURoute : NSObject
@property (assign,getter=isCurrentlyPicked,nonatomic) BOOL currentlyPicked;
@property (assign,getter=isSpeaker,nonatomic) BOOL speaker;
@end

@interface TURouteController : NSObject
@property (nonatomic,copy,readonly) NSArray * routes;
@property (nonatomic,copy,readonly) TURoute * pickedRoute;
@property (nonatomic,copy,readonly) TURoute * receiverRoute;
@property (nonatomic,copy,readonly) TURoute * speakerRoute;
-(void)pickRoute:(id)arg1 ;
@end

@interface TURouteController (UI)
@property(readonly, copy, nonatomic) TURoute *routeForSpeakerDisable;
@property(readonly, copy, nonatomic) TURoute *routeForSpeakerEnable;
@end

@interface TUCallCenter : NSObject
@property (nonatomic,retain) TURouteController * routeController;
+(id)sharedInstance;
@end

@interface PHCallViewController : UIViewController
@end

@interface PHAudioCallViewController : PHCallViewController
- (void)revealAudioRoutingDeviceListAnimated:(BOOL)arg1;
@end

@interface PHAudioCallControlsView : UIView
@property(nonatomic) __weak id delegate;
- (void)setSelectedState:(BOOL)arg1 forControlType:(unsigned long long)arg2;
- (void)reloadButtonViewStates;
@end

@interface PHAudioCallControlsViewController : UIViewController
@property __weak id delegate;
@property(retain) PHAudioCallControlsView *controlsView;
@end

@interface PHAudioControlsButton : UIButton
@property(nonatomic) unsigned long long controlType;
@property(nonatomic) __weak id menuDataSource;
- (void)setSelected:(BOOL)arg1;
@end
