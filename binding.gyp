{
    "targets": [],
    "conditions" : [
        ["OS=='win'", {
            "targets": [

                {
                    "target_name": "download_sdk",
                    "type": "none",
                    "actions": [
                        {
                            "action_name": "run_download_script",
                            "inputs": [ ],
                            "outputs": [ "LED/" ],
                            "action": [ "node", "./download-sdk" ]
                        }
                    ]
                },

                {
                    "target_name": "bindings",
                    "dependencies": [ "download_sdk" ],
                    "sources": [
                        "bindings.cc",
                        "functions.cc"
                    ],
                    "include_dirs" : [
                        "<!(node -e \"require('nan')\")",
                        "LED/Include"
                    ],
                    "conditions" : [
                        ["target_arch=='ia32'", {
                            'link_settings': {
                                "libraries": [ "-l../LED/Lib/x86/LogitechLEDLib.lib" ]
                            }
                        }],
                        ["target_arch=='x64'", {
                            'link_settings': {
                                "libraries": [ "-l../LED/Lib/x64/LogitechLEDLib.lib" ]
                            }
                        }]
                    ],
                },

                {
                    "target_name": "copy_target",
                    "dependencies": [ "bindings" ],
                    "type": "none",
                    "copies": [
                        {
                            "files": [
                                "<(PRODUCT_DIR)/bindings.node",
                                "<(PRODUCT_DIR)/bindings.pdb"
                            ],
                            "destination": "dist/<(target_arch)"
                        }
                    ]
                },
                
                {
                    "target_name": "build_constants",
                    "type": "none",
                    "actions": [
                        {
                            "action_name": "run_typescript_compiler",
                            "inputs": [ "constants.ts" ],
                            "outputs": [ "dist/constants.js" ],
                            "action": [
                                "tsc",
                                    "--removeComments",
                                    "--preserveConstEnums",
                                    "--outDir", "dist",
                                    
                                    "constants.ts"
                            ]
                        }
                    ]
                }
                
            ],
        }]
    ]
}