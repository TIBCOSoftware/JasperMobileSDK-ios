/*
 * Copyright © 2016 - 2017. TIBCO Software Inc. All Rights Reserved. Confidential & Proprietary.
 */


#import "JSReport.h"
#import "JSReportOption.h"
#import "JSResourceLookup.h"
#import "JSInputControlDescriptor.h"
#import "JSReportParameter.h"
#import "JSReportComponent.h"
#import "JSReportBookmark.h"
#import "JSReportPart.h"

NSString * const JSReportIsMutlipageDidChangedNotification  = @"JSReportIsMutlipageDidChangedNotification";
NSString * const JSReportCountOfPagesDidChangeNotification  = @"JSReportCountOfPagesDidChangeNotification";
NSString * const JSReportCurrentPageDidChangeNotification   = @"JSReportCurrentPageDidChangeNotification";
NSString * const JSReportBookmarksDidUpdateNotification     = @"JSReportBookmarksDidUpdateNotification";
NSString * const JSReportPartsDidUpdateNotification         = @"JSReportPartsDidUpdateNotification";

@interface JSReport()
@property (nonatomic, strong) NSMutableArray *availableReportOptions;
// setters
@property (nonatomic, assign, readwrite) NSInteger currentPage;
@property (nonatomic, assign, readwrite) NSInteger countOfPages;
@property (nonatomic, assign, readwrite) BOOL isMultiPageReport;
@property (nonatomic, strong, readwrite) NSString *requestId;

// html
@property (nonatomic, copy, readwrite) NSString *HTMLString;
@property (nonatomic, copy, readwrite) NSString *baseURLString;
@end

@implementation JSReport
@dynamic reportURI;


#pragma mark - LifeCycle
- (instancetype)initWithResourceLookup:(JSResourceLookup *)resourceLookup
{
    self = [super init];
    if (self) {
        _resourceLookup = resourceLookup;
        [self restoreDefaultState];
    }
    return self;
}

+ (instancetype)reportWithResourceLookup:(JSResourceLookup *)resourceLookup
{
    return [[self alloc] initWithResourceLookup:resourceLookup];
}


#pragma mark - Custom accessors
- (void)setIsMultiPageReport:(BOOL)isMultiPageReport
{
    _isMultiPageReport = isMultiPageReport;
    if (isMultiPageReport) {
        [self postNotificationMultipageReport];
    }
}

- (void)setCountOfPages:(NSInteger)countOfPages
{
    _countOfPages = countOfPages;
    [self postNotificationCountOfPages];
}

- (void)setCurrentPage:(NSInteger)currentPage
{
    _currentPage = currentPage;
    if (currentPage != NSNotFound) {
        [self postNotificationCurrentPageChanged];
    }
}

- (NSString *)reportURI
{
    return self.resourceLookup.uri;
}

- (void)setReportComponents:(NSArray *)reportComponents
{
    _reportComponents = [reportComponents copy];

    self.elasticChart = NO;
    for (JSReportComponent *component in reportComponents) {
        if (component.type == JSReportComponentTypeChart) {
            NSArray *services = ((JSReportComponentChartStructure *)component.structure).services;
            if (services.count == 1) {
                JSHighchartServiceType serviceType = (JSHighchartServiceType) ((NSNumber *)services.firstObject).integerValue;
                if (serviceType == JSHighchartServiceTypeAdhoc) {
                    self.elasticChart = YES;
                    break;
                }
            }
        }
    }
}

- (void)setBookmarks:(NSArray<JSReportBookmark *> *)bookmarks
{
    _bookmarks = bookmarks;
    [[NSNotificationCenter defaultCenter] postNotificationName:JSReportBookmarksDidUpdateNotification
                                                        object:self];
}

- (void)setParts:(NSArray<JSReportPart *> *)parts
{
    _parts = parts;
    [[NSNotificationCenter defaultCenter] postNotificationName:JSReportPartsDidUpdateNotification
                                                        object:self];
}

#pragma mark - Public API

- (void)updateCurrentPage:(NSInteger)currentPage
{
    if (self.currentPage == currentPage) {
        return;
    }

    self.currentPage = currentPage;
}

- (void)updateCountOfPages:(NSInteger)countOfPages
{
    if (self.countOfPages == countOfPages) {
        return;
    }

    self.countOfPages = countOfPages;
}

- (void)updateHTMLString:(NSString *)HTMLString
            baseURLSring:(NSString *)baseURLString
{
    self.HTMLString = HTMLString;
    self.baseURLString = baseURLString;
}

- (void)updateRequestId:(NSString *)requestId
{
    self.requestId = requestId;
}

- (void)updateIsMultiPageReport:(BOOL)isMultiPageReport
{
    self.isMultiPageReport = isMultiPageReport;
}

#pragma mark - Notifications
- (void)postNotificationMultipageReport
{
    [[NSNotificationCenter defaultCenter] postNotificationName:JSReportIsMutlipageDidChangedNotification
                                                        object:self];
}

- (void)postNotificationCountOfPages
{
    [[NSNotificationCenter defaultCenter] postNotificationName:JSReportCountOfPagesDidChangeNotification
                                                        object:self];
}

- (void)postNotificationCurrentPageChanged
{
    [[NSNotificationCenter defaultCenter] postNotificationName:JSReportCurrentPageDidChangeNotification
                                                        object:self];
}

#pragma mark - Restore default state
- (void)restoreDefaultState
{
    self.HTMLString = nil;
    self.baseURLString = nil;
    self.currentPage = NSNotFound;
    self.countOfPages = NSNotFound;
    self.isMultiPageReport = NO;
    self.reportParameters = nil;
    self.requestId = nil;
    self.bookmarks = nil;
    self.parts = nil;
}

#pragma mark - Helpers
- (NSString *)description
{
    NSString *description = [NSString stringWithFormat:@"\nReport: %@\ncount of pages: %@", self.resourceLookup.label, @(self.countOfPages)];
    return description;
}

#pragma mark - NSCopying
- (id)copyWithZone:(NSZone *)zone {
    JSReport *newReport     = [[self class] allocWithZone:zone];
    newReport->_resourceLookup = [self.resourceLookup copyWithZone:zone];
    newReport.currentPage = self.currentPage;
    newReport.countOfPages = self.countOfPages;
    newReport.isMultiPageReport = self.isMultiPageReport;
    newReport.requestId = [self.requestId copyWithZone:zone];
    newReport.HTMLString = [self.HTMLString copyWithZone:zone];
    newReport.baseURLString = [self.baseURLString copyWithZone:zone];
    newReport.bookmarks = [self.bookmarks copyWithZone:zone];
    newReport.parts = [self.parts copyWithZone:zone];
    newReport.elasticChart = self.elasticChart;

    if (self.availableReportOptions.count) {
        newReport.availableReportOptions = [[NSMutableArray alloc] initWithArray:self.availableReportOptions copyItems:YES];
    }
    if (self.reportParameters.count) {
        newReport.reportParameters = [[NSArray alloc] initWithArray:self.reportParameters copyItems:YES];
    }
    if (self.reportComponents) {
        newReport.reportComponents = [[NSArray alloc] initWithArray:self.reportComponents copyItems:YES];
    }

    return newReport;
}

@end
