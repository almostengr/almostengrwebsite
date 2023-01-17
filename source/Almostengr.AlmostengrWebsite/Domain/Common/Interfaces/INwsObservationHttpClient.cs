using Almostengr.AlmostengrWebsite.Common;

namespace Almostengr.AlmostengrWebsite.Domain.Common.Interfaces;

public interface INwsObservationHttpClient
{
    Task<T> GetAsync<T>(string url) where T : BaseDto;
}