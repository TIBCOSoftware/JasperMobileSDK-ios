/*
 * Copyright © 2011 - 2017. TIBCO Software Inc. All Rights Reserved. Confidential & Proprietary.
 */


/**
 @author Giulio Toffoli giulio@jaspersoft.com
 @author Vlad Zavadskii vzavadskii@jaspersoft.com
 @author Oleksii Gubariev ogubarie@tibco.com
 @since 1.0
 */


/**
 Provides helping constants for different types of resources and API parts
 */

/**
 @name Error Codes
 @{
 */
typedef NS_ENUM (NSInteger, JSErrorCode) {
    JSOtherErrorCode                = 1000, // All other errors
    JSServerNotReachableErrorCode,          // Server not reachable error
    JSServerVersionNotSupportedErrorCode,   // Server version not supported error

    JSRequestTimeOutErrorCode,              // Request TimeOut error
    
    JSHTTPErrorCode,                        // HTTP erorrs (status codes 404, 500).
    
    JSInvalidCredentialsErrorCode,          // Invalid Credentilas error
    JSSessionExpiredErrorCode,              // Session expired error
    
    JSAccessDeniedErrorCode,                // Access denied error

    JSClientErrorCode,                      // Client error code - when JSErrorDescriptor are received
    
    JSDataMappingErrorCode,                 // Data Mapping error code - when responce did load successfully, but can't be parsed
    
    JSUnsupportedAcceptTypeErrorCode,       // Unsupported Accept Type error code - when responce did load successfully, but can't be parsed because has unsupported accept code

    JSFileSavingErrorCode                  // Write to file and file saving error
};
/** @} */

/**
 @name JS Version Codes
 @{
 */
extern NSString * const JSErrorDomain;
extern NSString * const JSHTTPErrorDomain;
extern NSString * const JSAuthErrorDomain;

/** @} */


/**
 @name JS Version Codes
 @{
 */
extern float const kJS_SERVER_VERSION_CODE_UNKNOWN;
extern float const kJS_SERVER_VERSION_CODE_EMERALD_5_5_0;
extern float const kJS_SERVER_VERSION_CODE_EMERALD_5_6_0;
extern float const kJS_SERVER_VERSION_CODE_AMBER_6_0_0;
extern float const kJS_SERVER_VERSION_CODE_AMBER_6_1_0;
extern float const kJS_SERVER_VERSION_CODE_JADE_6_2_0;
extern float const kJS_SERVER_VERSION_CODE_JADE_6_3_0;
extern float const kJS_SERVER_VERSION_CODE_Moonstone_6_4_0;
extern float const kJS_SERVER_VERSION_CODE_Moonstone_7_0_0;
/** @} */

/**
 @name JS Editions
 @{
 */
extern NSString *const kJS_SERVER_EDITION_CE;
extern NSString *const kJS_SERVER_EDITION_PRO;
/** @} */

/**
 @name Input Control Descriptor Types
 @{
 */
typedef NS_ENUM (NSInteger, kJS_ICD_TYPE) {
    kJS_ICD_TYPE_BOOL,
    kJS_ICD_TYPE_SINGLE_VALUE_TEXT,
    kJS_ICD_TYPE_SINGLE_VALUE_NUMBER,
    kJS_ICD_TYPE_SINGLE_VALUE_DATE,
    kJS_ICD_TYPE_SINGLE_VALUE_TIME,
    kJS_ICD_TYPE_SINGLE_VALUE_DATETIME,
    kJS_ICD_TYPE_SINGLE_SELECT,
    kJS_ICD_TYPE_SINGLE_SELECT_RADIO,
    kJS_ICD_TYPE_MULTI_SELECT,
    kJS_ICD_TYPE_MULTI_SELECT_CHECKBOX
};
/** @} */

/**
 @name Provided here from DataType for facility
 @{
 */
typedef NS_ENUM(NSInteger, kJS_DT_TYPE) {
    kJS_DT_TYPE_UNKNOWN = 0,
    kJS_DT_TYPE_TEXT = 1,
    kJS_DT_TYPE_NUMBER = 2,
    kJS_DT_TYPE_DATE = 3,
    kJS_DT_TYPE_DATE_TIME = 4,
    kJS_DT_TYPE_TIME = 5
};
/** @} */

/**
 @name WebService types
 @{
 */
extern NSString *const kJS_WS_TYPE_ACCESS_GRANT_SCHEMA;
extern NSString *const kJS_WS_TYPE_ADHOC_DATA_VIEW;
extern NSString *const kJS_WS_TYPE_ADHOC_REPORT;
extern NSString *const kJS_WS_TYPE_BEAN;
extern NSString *const kJS_WS_TYPE_CONTENT_RESOURCE;
extern NSString *const kJS_WS_TYPE_CSS;
extern NSString *const kJS_WS_TYPE_CUSTOM;
extern NSString *const kJS_WS_TYPE_DATASOURCE;
extern NSString *const kJS_WS_TYPE_DATATYPE;
extern NSString *const kJS_WS_TYPE_DASHBOARD;
extern NSString *const kJS_WS_TYPE_DASHBOARD_LEGACY;
extern NSString *const kJS_WS_TYPE_DASHBOARD_STATE;
extern NSString *const kJS_WS_TYPE_DOMAIN;
extern NSString *const kJS_WS_TYPE_DOMAIN_TOPIC;
extern NSString *const kJS_WS_TYPE_FILE;
extern NSString *const kJS_WS_TYPE_FOLDER;
extern NSString *const kJS_WS_TYPE_FONT;
extern NSString *const kJS_WS_TYPE_IMG;
extern NSString *const kJS_WS_TYPE_INPUT_CONTROL;
extern NSString *const kJS_WS_TYPE_JAR;
extern NSString *const kJS_WS_TYPE_JDBC;
extern NSString *const kJS_WS_TYPE_JNDI;
extern NSString *const kJS_WS_TYPE_JRXML;
extern NSString *const kJS_WS_TYPE_LOV;
extern NSString *const kJS_WS_TYPE_OLAP_MONDRIAN_CON;
extern NSString *const kJS_WS_TYPE_OLAP_MONDRIAN_SCHEMA;
extern NSString *const kJS_WS_TYPE_OLAP_UNIT;
extern NSString *const kJS_WS_TYPE_OLAP_XMLA_CON;
extern NSString *const kJS_WS_TYPE_PROP;
extern NSString *const kJS_WS_TYPE_QUERY;
extern NSString *const kJS_WS_TYPE_REFERENCE;
extern NSString *const kJS_WS_TYPE_REPORT_OPTIONS;
extern NSString *const kJS_WS_TYPE_REPORT_UNIT;
extern NSString *const kJS_WS_TYPE_XML;
extern NSString *const kJS_WS_TYPE_XMLA_CONNECTION;
extern NSString *const kJS_WS_TYPE_UNKNOW;
/** @} */

/**
 @name Output formats
 @{
 */
extern NSString *const kJS_CONTENT_TYPE_PDF;
extern NSString *const kJS_CONTENT_TYPE_HTML;
extern NSString *const kJS_CONTENT_TYPE_XLS;
extern NSString *const kJS_CONTENT_TYPE_XLSX;
extern NSString *const kJS_CONTENT_TYPE_RTF;
extern NSString *const kJS_CONTENT_TYPE_CSV;
extern NSString *const kJS_CONTENT_TYPE_IMG;
extern NSString *const kJS_CONTENT_TYPE_ODT;
extern NSString *const kJS_CONTENT_TYPE_ODS;
extern NSString *const kJS_CONTENT_TYPE_JSON;
extern NSString *const kJS_CONTENT_TYPE_PPT;
extern NSString *const kJS_CONTENT_TYPE_PPTX;
extern NSString *const kJS_CONTENT_TYPE_DOC;
extern NSString *const kJS_CONTENT_TYPE_DOCX;
extern NSString *const kJS_CONTENT_TYPE_PNG;

/** @} */

/**
 @name REST URI Prefixes
 @{
 */
extern NSString *const kJS_REST_ENCRYPTION_KEY_URI;
extern NSString *const kJS_REST_AUTHENTICATION_URI;
extern NSString *const kJS_REST_LOGOUT_URI;
extern NSString *const kJS_REST_SERVICES_URI;
extern NSString *const kJS_REST_SERVICES_V2_URI;
extern NSString *const kJS_REST_RESOURCE_URI;
extern NSString *const kJS_REST_RESOURCES_URI;
extern NSString *const kJS_REST_RESOURCE_THUMBNAIL_URI;
extern NSString *const kJS_REST_REPORT_URI;
extern NSString *const kJS_REST_REPORTS_URI;
extern NSString *const kJS_REST_REPORT_OPTIONS_URI;
extern NSString *const kJS_REST_INPUT_CONTROLS_URI;
extern NSString *const kJS_REST_VALUES_URI;
extern NSString *const kJS_REST_SERVER_INFO_URI;
extern NSString *const kJS_REST_ORGANIZATIONS_URI;
extern NSString *const kJS_REST_ROLES_URI;
extern NSString *const kJS_REST_REPORT_EXECUTION_URI;
extern NSString *const kJS_REST_REPORT_EXECUTION_STATUS_URI;
extern NSString *const kJS_REST_EXPORT_EXECUTION_URI;
extern NSString *const kJS_REST_EXPORT_EXECUTION_ATTACHMENTS_PREFIX_URI;
extern NSString *const kJS_REST_DASHBOARD_EXECUTION_URI;
extern NSString *const kJS_REST_DASHBOARD_EXECUTION_STATUS_URI;
/** @} */


/**
 @name Execution status checking
 @{
 */
extern NSTimeInterval const kJSExecutionStatusCheckingInterval;

typedef NS_ENUM(NSInteger, kJS_EXECUTION_STATUS) {
    kJS_EXECUTION_STATUS_UNKNOWN = 0,
    kJS_EXECUTION_STATUS_READY,
    kJS_EXECUTION_STATUS_QUEUED,
    kJS_EXECUTION_STATUS_EXECUTION,
    kJS_EXECUTION_STATUS_CANCELED,
    kJS_EXECUTION_STATUS_FAILED
};

/** @} */

/**
 @name Markup Type
 @{
 */

typedef NS_ENUM(NSInteger, JSMarkupType) {
    JSMarkupTypeFull,
    JSMarkupTypeEmbeddable
};

/** @} */

extern NSString *const JSRestClientDidChangeCookies;
extern NSString *const JSReportLoaderDidSetReportNotification;
