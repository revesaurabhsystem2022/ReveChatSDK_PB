// swift-tools-version: 6.1
import PackageDescription

let package = Package(
    name: "ReveChatSDK_PB",
    defaultLocalization: "en",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        .library(
            name: "ReveChatSDK_PB",
            targets: ["ReveChatSDK_PB"]
        )
    ],
    dependencies: [
    ],
    targets: [
        // Remote XCFramework - ReveChatSDK
        .binaryTarget(
            name: "ReveChatSDK_PBBinary",
            url: "https://github.com/revesaurabhsystem2022/ReveChatSDK_PB/releases/download/1.0.0/ReveChatSDK_PB.xcframework.zip",
            checksum: "436c86c2baad4a3b1c29d88539842ec4b3cde8e65fa36df575566bdedeca2ce1"
        ),

        // Remote XCFramework - AFNetworking
        .binaryTarget(
            name: "AFNetworking",
            url: "https://github.com/revesaurabhsystem2022/ReveChatSDK_PB/releases/download/1.0.0/AFNetworking.xcframework.zip",
            checksum: "3210d9a5508febc628bdc611766c68870a2c1211261ecfb907db5220ac459f8a"
        ),

        // Remote XCFramework - WebRTC
        .binaryTarget(
            name: "WebRTC",
            url: "https://github.com/revesaurabhsystem2022/ReveChatSDK_PB/releases/download/1.0.0/WebRTC.xcframework.zip",
            checksum: "0adcbddd9339ecdbb5905ea195710319c32e9e5f0a13075fb0a0ab8ae62265e4"
        ),

        // Wrapper Target
        .target(
            name: "ReveChatSDK_PB",
            dependencies: [
                "ReveChatSDK_PBBinary",
                "AFNetworking",
                "WebRTC"
            ],
            path: "Sources/ReveChatSDK_PB",
            publicHeadersPath: "include"
        )
    ]
)
