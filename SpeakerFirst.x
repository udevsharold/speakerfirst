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

#import "PrivateHeaders.h"

%hook PHAudioControlsButton
-(void)setContextMenuIsPrimary:(BOOL)primary{
	if (self.controlType == 3){
		%orig(NO);
		[self addTarget:self action:@selector(audioRoutesButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
		return;
	}
	%orig(primary);
}

%new
-(void)audioRoutesButtonTapped:(id)sender{
	if (self.controlType == 3){
		TUCallCenter *callCenter = [%c(TUCallCenter) sharedInstance];
		
		if (!callCenter.routeController.routeForSpeakerEnable && !callCenter.routeController.routeForSpeakerDisable){
			[(PHAudioCallViewController *)(((PHAudioCallControlsViewController *)(((PHAudioCallControlsView *)(self.menuDataSource)).delegate)).delegate) revealAudioRoutingDeviceListAnimated:YES];
		}
		
		if (!callCenter.routeController.pickedRoute.speaker){
			[callCenter.routeController pickRoute:callCenter.routeController.routeForSpeakerEnable];
		}else{
			[callCenter.routeController pickRoute:callCenter.routeController.routeForSpeakerDisable];
		}
	}
}
%end
