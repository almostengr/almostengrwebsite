using System.Collections.Generic;

namespace Almostengr.AlmostengrWebsite.YouTubeContent.Models
{
    public class YtLatestVideoFeed
    {
        public string Version { get; set; }
        public string Title { get; set; }
        public List<YtVideo> Items { get; set; }
    }
}