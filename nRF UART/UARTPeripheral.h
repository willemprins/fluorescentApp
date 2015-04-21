//
//  UARTPeripheral.h
//  nRF UART
//
//  Created by Ole Morten on 1/12/13.
//  Copyright (c) 2013 Nordic Semiconductor. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol UARTPeripheralDelegate
- (void) didReceiveData:(NSString *) string;
@optional
- (void) didReadHardwareRevisionString:(NSString *) string;
@end


@interface UARTPeripheral : NSObject <CBPeripheralDelegate>
@property CBPeripheral *peripheral;
@property id<UARTPeripheralDelegate> delegate;
//Do I need to put the NSMutableArray here?
//@property (nonatomic) 

+ (CBUUID *) uartServiceUUID;

- (UARTPeripheral *) initWithPeripheral:(CBPeripheral*)peripheral delegate:(id<UARTPeripheralDelegate>) delegate;

- (void) writeString:(NSString *) string;

- (void) didConnect;
- (void) didDisconnect;
@end
