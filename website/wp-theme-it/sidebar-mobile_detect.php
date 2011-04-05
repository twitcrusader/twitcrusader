<?php

/**
 * Mobile Detect
 *
 * @license    http://www.opensource.org/licenses/mit-license.php The MIT License
 * @version    SVN: $Id: Mobile_Detect.php 3 2009-05-21 13:06:28Z vic.stanciu $
 * @Download http://code.google.com/p/php-mobile-detect/downloads/list
 */

class Mobile_Detect {
    
    protected $accept;
    protected $userAgent;
    
    protected $isMobile     = false;
    protected $isAndroid    = null;
    protected $isBlackberry = null;
    protected $isOpera      = null;
    protected $isPalm       = null;
    protected $isWindows    = null;
    protected $isGeneric    = null;

	// @ptkdev fixed all devices
    protected $devices = array(
        "android"       => "android",
        "blackberry"    => "blackberry",
        "iphone"        => "(iphone|ipod)",
        "opera"         => "opera mini",
        "palm"          => "(avantgo|blazer|elaine|hiptop|palm|plucker|xiino)",
        "windows"       => "windows ce; (iemobile|ppc|smartphone)",
        "generic"       => "(2.0 MMP|240x320|400X240|AvantGo|BlackBerry|Blazer|Cellphone|Danger|DoCoMo|Elaine 3.0|EudoraWeb|Googlebot-Mobile|hiptop|IEMobile|KYOCERA|WX310K|LG U990|MIDP-2.|MMEF20|MOT-V|NetFront|Newt|Nintendo Wii|Nitro|Nokia|Opera Mini|Palm|PlayStation Portable|portalmmm|Proxinet|ProxiNet|SHARP-TQ-GX10|SHG-i900|Small|SonyEricsson|Symbian OS|SymbianOS|TS21i-10|UP.Browser|UP.Link|webOS|Windows CE|WinWAP|YahooSeeker|M1A1-R2D2|iPhone|iPod|Android|BlackBerry9530|LG-TU915 Obigo|LGE VX|webOS|Nokia5800)"
    );


    public function __construct() {
        $this->userAgent = $_SERVER['HTTP_USER_AGENT'];
        $this->accept    = $_SERVER['HTTP_ACCEPT'];

        if (isset($_SERVER['HTTP_X_WAP_PROFILE'])|| isset($_SERVER['HTTP_PROFILE'])) {
            $this->isMobile = true;
        } elseif (strpos($this->accept,'text/vnd.wap.wml') > 0 || strpos($accept,'application/vnd.wap.xhtml+xml') > 0) {
            $this->isMobile = true;
        } else {
            foreach ($this->devices as $device => $regexp) {
                if ($this->isDevice($device)) {
                    $this->isMobile = true;
                }
            }
        }
    }


    /**
     * Overloads isAndroid() | isBlackberry() | isOpera() | isPalm() | isWindows() | isGeneric() through isDevice()
     *
     * @param string $name
     * @param array $arguments
     * @return bool
     */
    public function __call($name, $arguments) {
        $device = substr($name, 2);
        if ($name == "is" . ucfirst($device)) {
            return $this->isDevice($device);
        } else {
            trigger_error("Method $name not defined", E_USER_ERROR);
        }
    }


    /**
     * Returns true if any type of mobile device detected, including special ones
     * @return bool
     */
    public function isMobile() {
        return $this->isMobile;
    }


    protected function isDevice($device) {
        $var    = "is" . ucfirst($device);
        $return = $this->$var === null ? (bool) preg_match("/" . $this->devices[$device] . "/i", $this->userAgent) : $this->$var;

        if ($device != 'generic' && $return == true) {
            $this->isGeneric = false;
        }

        return $return;
    }
}
