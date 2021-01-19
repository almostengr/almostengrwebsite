using Microsoft.Extensions.Configuration;

namespace Almostengr.WebsiteTests
{
    public class Configuration{
        public string ChromeDriverPath {get ;set;}
        public string WebsiteUrl {get ;set;}

        public Configuration() {
        }
    }
}