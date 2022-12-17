FT.manifest({
    "filename": "index.html",
    "width": 300,
    "height": 600,
    "clickTagCount": 4,
    "richLoads": [
        { "name": "richload", "src": "BestBuy_FY23_Goalification_300x600" }
    ],
    "instantAds": [
        { "name": "richload", "type": "richload", "default": "BestBuy_FY23_Goalification_300x600" },
        { "name": "backgroundimage", "type": "image", "default": "images/bg_300x600.jpg" },
        { "name": "logoimage", "type": "image", "default": "images/bb_logo_white_300x600.png" },
        { "name": "frame2_image", "type": "image", "default": "images/blank.gif" },
        { "name": "frame3_coremessage_image", "type": "image", "default": "images/Frame3_FreeShipping_300x600.png" },
        { "name": "feedEndpoint", "type": "text", "default": "https://fm.flashtalking.com/feed/175/specific/6494240,6494231,6494232,6494241,6494243,&shuffle=true&numItems=3" },
        { "name": "defaultfeedendpoint", "type": "text", "default": "https://fm.flashtalking.com/feed/175/specific/6494240,6494231,6494232,6494241,6494243,&shuffle=true&numItems=3" },
        { "name": "default_fallback_image", "type": "image", "default": "images/blank.gif" },
        { "name": "legal_text", "type": "text", "default": "©2022 Best Buy" },
        { "name": "frame2_url", "type": "text", "default": "frame2URL" },
        { "name": "product_frame_url", "type": "text", "default": "produrl" },
        { "name": "cta_text", "type": "text", "default": "Shop Now" },
        { "name": "product_brand_logo", "type": "image", "default": "images/blank.gif" },
        { "name": "segmentId", "type": "text", "default": "false" },
        { "name": "NumberofProducts", "type": "text", "default": "4" }
    ],
    "trackingEvents":[
      {"name":"Defaultendpoint","type":"string"},
      {"name":"Feedfail","type":"string"}
    ]
  });
  